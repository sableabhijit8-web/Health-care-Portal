document.addEventListener("DOMContentLoaded", function () {
  
  // --- Theme Logic ---
  const toggleDarkModeBtn = document.getElementById("toggle-dark-mode");
  const themeSelector = document.getElementById("theme-selector");

  toggleDarkModeBtn?.addEventListener("click", () => {
    document.body.classList.toggle("dark-mode");
    updateThemeIcon();
  });

  themeSelector?.addEventListener("change", (e) => {
    document.body.className = ""; // Remove all theme classes
    if (e.target.value === "dark") {
        document.body.classList.add("dark-mode");
    } else if (e.target.value !== "default") {
        document.body.classList.add(`${e.target.value}-theme`);
    }
    updateThemeIcon();
  });

  function updateThemeIcon() {
    const isDark = document.body.classList.contains("dark-mode");
    if (toggleDarkModeBtn) {
      toggleDarkModeBtn.textContent = isDark ? "☀" : "🌙";
    }
    // Sync dropdown with dark mode toggle
    if (themeSelector) {
        if (isDark) {
            themeSelector.value = "dark";
        } else if (!document.body.className) {
            themeSelector.value = "default";
        }
    }
  }
  // --- End of Theme Logic ---


  // --- Login Form Logic ---
  const loginForm = document.getElementById("login-form");
  const usernameInput = document.getElementById("username");
  const passwordInput = document.getElementById("password");
  const errorMessage = document.getElementById("error-message");

  loginForm.addEventListener("submit", function (e) {
    e.preventDefault(); 

    const username = usernameInput.value.trim();
    const password = passwordInput.value;
    
    // This checks for the *specific* username and password
    if (username === "patient" && password === "pass123") {
      // Success: Go to the main dashboard
      window.location.href = "index.html"; 
    } else {
      // Failure: Show error. Does not work on "random names"
      errorMessage.classList.remove("hidden");
    }
  });

  // Run on page load to set the correct theme icon
  updateThemeIcon(); 

});