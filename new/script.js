 
  document.addEventListener("DOMContentLoaded", function () {
  const toggleDarkModeBtn = document.getElementById("toggle-dark-mode");
  const themeSelector = document.getElementById("theme-selector");
  const searchButton = document.getElementById("search-btn");
  const usernameInput = document.getElementById("user-input");
  const searchHistoryEle = document.getElementById("search-history");
  const clearHistoryBtn = document.getElementById("clear-history-btn");
  const loadingSpinner = document.getElementById("loading-spinner");
  const statsCardsContainer = document.getElementById("stats-cards");

  let searchHistory = [];
  let currentTheme = "default";

  toggleDarkModeBtn?.addEventListener("click", () => {
    document.body.classList.toggle("dark-mode");
    updateThemeIcon();
  });

  themeSelector?.addEventListener("change", () => {
    document.body.className = "";
    currentTheme = themeSelector.value;

    if (themeSelector.value === "dark") {
      document.body.classList.add("dark-mode");
    } else if (themeSelector.value === "blue") {
      document.body.classList.add("blue-theme");
    }
    updateThemeIcon();
  });

  function updateThemeIcon() {
    const isDark = document.body.classList.contains("dark-mode");
    if (toggleDarkModeBtn) {
      toggleDarkModeBtn.textContent = isDark ? "☀" : "🌙";
    }
  }

  function updateSearchHistory() {
    if (!searchHistoryEle) return;
    searchHistoryEle.innerHTML = "";
    searchHistory.forEach((item) => {
      const li = document.createElement("li");
      li.textContent = item;
      li.addEventListener("click", () => {
        usernameInput.value = item;
      });
      searchHistoryEle.appendChild(li);
    });
  }

  clearHistoryBtn?.addEventListener("click", () => {
    searchHistory = [];
    updateSearchHistory();
  });

  function createStatsCards(userData) {
    const stats = [
      { title: "Total Solved", value: userData.totalSolved, label: "Problems" },
      { title: "Acceptance Rate", value: userData.acceptanceRate + "%", label: "Success Rate" },
      { title: "Ranking", value: userData.ranking, label: "Global Rank" },
      { title: "Reputation", value: userData.reputation, label: "Points" },
    ];

    if (!statsCardsContainer) return;
    statsCardsContainer.innerHTML = "";
    stats.forEach((stat) => {
      const card = document.createElement("div");
      card.className = "stat-card";
      card.innerHTML = `
        <h3>${stat.title}</h3>
        <div class="value">${stat.value}</div>
        <div class="label">${stat.label}</div>
      `;
      statsCardsContainer.appendChild(card);
    });
  }

  searchButton?.addEventListener("click", () => {
    const username = usernameInput.value.trim();
    if (username === "") return;

    loadingSpinner?.classList.remove("hidden");

    setTimeout(() => {
      loadingSpinner?.classList.add("hidden");

      const easySolved = Math.floor(Math.random() * 200) + 50;
      const mediumSolved = Math.floor(Math.random() * 300) + 100;
      const hardSolved = Math.floor(Math.random() * 150) + 20;
      const totalSolved = easySolved + mediumSolved + hardSolved;

      const userData = {
        totalSolved,
        acceptanceRate: Math.floor(Math.random() * 30) + 60,
        ranking: Math.floor(Math.random() * 100000) + 1000,
        reputation: Math.floor(Math.random() * 5000) + 1000,
      };

      updateProgress("easy-progress", "easy-level", easySolved, 800);
      updateProgress("medium-progress", "medium-progress", mediumSolved, 1200);
      updateProgress("hard-progress", "hard-level", hardSolved, 400);

      createStatsCards(userData);

      if (!searchHistory.includes(username)) {
        searchHistory.push(username);
        updateSearchHistory();
      }
    }, 1500);
  });

  usernameInput?.addEventListener("keypress", (e) => {
    if (e.key === "Enter") {
      searchButton.click();
    }
  });

  function updateProgress(progressClass, labelId, solved, total) {
    const progressEle = document.querySelector(`.${progressClass}`);
    const labelEle = document.getElementById(labelId);

    const percentage = Math.min((solved / total) * 100, 100);
    const degree = `${percentage * 3.6}deg`;

    progressEle?.style.setProperty("--progress-degree", degree);
    if (labelEle) {
      labelEle.textContent = `${solved} Solved`;
    }
  }

  updateSearchHistory();
});
