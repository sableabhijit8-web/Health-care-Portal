document.addEventListener("DOMContentLoaded", () => {
    const toggleDarkModeBtn = document.getElementById("toggle-dark-mode");
    const searchButton = document.getElementById("search-btn");
    const usernameInput = document.getElementById("user-input");
    const searchHistoryEle = document.getElementById("search-history");
    const clearHistoryBtn = document.getElementById("clear-history-btn");

    const avatar = document.getElementById("avatar");
    const nameEle = document.getElementById("name");
    const bioEle = document.getElementById("bio");
    const followersEle = document.getElementById("followers");
    const followingEle = document.getElementById("following");
    const reposEle = document.getElementById("repos");
    const joinDateEle = document.getElementById("join-date");
    const profileLink = document.getElementById("profile-link");

    // Theme persistence
    if (localStorage.getItem("theme") === "dark") {
        document.body.classList.add("dark-mode");
    }

    toggleDarkModeBtn.addEventListener("click", () => {
        document.body.classList.toggle("dark-mode");
        localStorage.setItem("theme", document.body.classList.contains("dark-mode") ? "dark" : "light");
    });

    // Live clock
    setInterval(() => {
        document.getElementById("clock").textContent = new Date().toLocaleTimeString();
    }, 1000);

    // Fetch GitHub data
    async function fetchGitHubUser(username) {
        try {
            const res = await fetch(`https://api.github.com/users/${username}`);
            if (!res.ok) throw new Error("User not found");
            const data = await res.json();

            avatar.src = data.avatar_url;
            profileLink.href = data.html_url;
            nameEle.textContent = data.name || "No name available";
            bioEle.textContent = data.bio || "No bio available";
            followersEle.textContent = data.followers;
            followingEle.textContent = data.following;
            reposEle.textContent = data.public_repos;
            joinDateEle.textContent = new Date(data.created_at).toDateString();

            // Animate progress (mock stats)
            animateCircle(".easy-progress", Math.floor(Math.random() * 100));
            animateCircle(".medium-progress", Math.floor(Math.random() * 100));
            animateCircle(".hard-progress", Math.floor(Math.random() * 100));

            saveSearchHistory(username);
        } catch (err) {
            alert(err.message);
        }
    }

    // Animate circle text
    function animateCircle(selector, target) {
        const circle = document.querySelector(selector);
        let count = 0;
        const interval = setInterval(() => {
            circle.textContent = `${count}%`;
            if (count >= target) clearInterval(interval);
            count++;
        }, 15);
    }

    // Search history
    function saveSearchHistory(username) {
        let history = JSON.parse(localStorage.getItem("history") || "[]");
        if (!history.includes(username)) {
            history.push(username);
            localStorage.setItem("history", JSON.stringify(history));
        }
        renderHistory();
    }

    function renderHistory() {
        searchHistoryEle.innerHTML = "";
        let history = JSON.parse(localStorage.getItem("history") || "[]");
        history.forEach(user => {
            const li = document.createElement("li");
            li.textContent = user;
            li.addEventListener("click", () => fetchGitHubUser(user));
            searchHistoryEle.appendChild(li);
        });
    }

    clearHistoryBtn.addEventListener("click", () => {
        localStorage.removeItem("history");
        renderHistory();
    });

    searchButton.addEventListener("click", () => {
        const username = usernameInput.value.trim();
        if (username) fetchGitHubUser(username);
    });

    renderHistory();
});
