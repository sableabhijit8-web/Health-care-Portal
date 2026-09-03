document.addEventListener("DOMContentLoaded", function () {
  // --- Element Selections ---
  const toggleDarkModeBtn = document.getElementById("toggle-dark-mode");
  const themeSelector = document.getElementById("theme-selector");
  const searchButton = document.getElementById("search-btn");
  const usernameInput = document.getElementById("user-input");
  const searchHistoryEle = document.getElementById("search-history");
  const clearHistoryBtn = document.getElementById("clear-history-btn");
  const loadingSpinner = document.getElementById("loading-spinner");
  const statsCardsContainer = document.getElementById("stats-cards");
  const progressContainer = document.querySelector(".progress");

  // Feedback Elements
  const feedbackForm = document.getElementById("feedback-form");
  const patientNameInput = document.getElementById("patient-name");
  const patientRatingInput = document.getElementById("patient-rating");
  const patientCommentInput = document.getElementById("patient-comment");
  const feedbackList = document.getElementById("feedback-list");
  const feedbackContainer = document.querySelector(".feedback-container");

  // Appointment Elements
  const appointmentContainer = document.querySelector(".appointment-container");
  const appointmentForm = document.getElementById("appointment-form");
  const apptPatientNameInput = document.getElementById("appt-patient-name");
  const apptDateInput = document.getElementById("appt-date");
  const apptTimeInput = document.getElementById("appt-time");
  const apptReasonInput = document.getElementById("appt-reason");
  const appointmentList = document.getElementById("appointment-list");
  
  // --- State Variables ---
  let searchHistory = [];
  let patientFeedback = [];
  let bookedAppointments = [];

  // --- Data ---
  const diseaseData = [
    { id: "easy", name: "BP patient", progressClass: "easy-progress", labelId: "easy-level", max: 800 },
    { id: "medium", name: "HB patient", progressClass: "medium-progress", labelId: "medium-progress", max: 1200 },
    { id: "hard", name: "Diabetes patient", progressClass: "hard-progress", labelId: "hard-level", max: 400 },
    { id: "asthma", name: "Asthma patient", progressClass: "asthma-progress", labelId: "asthma-level", max: 300 },
    { id: "heart", name: "Heart patient", progressClass: "heart-progress", labelId: "heart-level", max: 500 },
  ];

  // --- Simulated Doctor Database ---
  const doctorDatabase = {
    "abhi123": {
      bp_patients: 650,
      hb_patients: 920,
      diabetes_patients: 310,
      asthma_patients: 180,
      heart_patients: 410,
      acceptanceRate: 88,
      ranking: 12050,
      reputation: 4500
    },
    "drsmith": {
      bp_patients: 420,
      hb_patients: 700,
      diabetes_patients: 200,
      asthma_patients: 90,
      heart_patients: 250,
      acceptanceRate: 94,
      ranking: 8500,
      reputation: 5200
    },
    "drpatel": {
      bp_patients: 750,
      hb_patients: 1100,
      diabetes_patients: 380,
      asthma_patients: 250,
      heart_patients: 480,
      acceptanceRate: 82,
      ranking: 15000,
      reputation: 4100
    }
  };
  // ---------------------------------

  // --- Load Data from localStorage ---
  const storedHistory = localStorage.getItem("searchHistory");
  if (storedHistory) {
    searchHistory = JSON.parse(storedHistory);
  }

  const storedFeedback = localStorage.getItem("patientFeedback");
  if (storedFeedback) {
    patientFeedback = JSON.parse(storedFeedback);
  }

  const storedAppointments = localStorage.getItem("bookedAppointments");
  if (storedAppointments) {
    bookedAppointments = JSON.parse(storedAppointments);
  }

  // --- Theme Toggling Logic ---
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

  // --- Search History Functions ---
  function updateSearchHistory() {
    if (!searchHistoryEle) return;
    searchHistoryEle.innerHTML = "";
    searchHistory.forEach((item) => {
      const li = document.createElement("li");
      li.textContent = item;
      li.addEventListener("click", () => {
        usernameInput.value = item;
        searchButton.click();
      });
      searchHistoryEle.appendChild(li);
    });
    localStorage.setItem("searchHistory", JSON.stringify(searchHistory));
  }

  clearHistoryBtn?.addEventListener("click", () => {
    if (confirm("Are you sure you want to clear your search history?")) {
      searchHistory = [];
      updateSearchHistory();
    }
  });

  // --- Feedback Functions ---
  function saveFeedback() {
    localStorage.setItem("patientFeedback", JSON.stringify(patientFeedback));
  }

  function renderFeedback() {
    if (!feedbackList) return;
    feedbackList.innerHTML = ""; 
    patientFeedback.forEach(item => {
      const feedbackItem = document.createElement("div");
      feedbackItem.className = "feedback-item";
      let ratingStars = "";
      for (let i = 0; i < 5; i++) {
        ratingStars += i < item.rating ? "★" : "☆";
      }
      feedbackItem.innerHTML = `
        <div class="feedback-header">
          <span class="feedback-name">${item.name}</span>
          <span class="feedback-rating">${ratingStars}</span>
        </div>
        <p class="feedback-body">"${item.comment}"</p>
      `;
      feedbackList.appendChild(feedbackItem);
    });
  }

  // --- Appointment Functions ---
  function saveAppointments() {
    localStorage.setItem("bookedAppointments", JSON.stringify(bookedAppointments));
  }

  function renderAppointments() {
    if (!appointmentList) return;
    appointmentList.innerHTML = "";

    if (bookedAppointments.length === 0) {
      appointmentList.innerHTML = "<p>No appointments booked yet.</p>";
      return;
    }

    bookedAppointments.sort((a, b) => new Date(a.dateTime) - new Date(b.dateTime));

    bookedAppointments.forEach(appt => {
      const apptItem = document.createElement("div");
      apptItem.className = "appointment-item";
      const apptDate = new Date(appt.dateTime);
      const formattedDate = apptDate.toLocaleDateString(undefined, {
        weekday: 'long', year: 'numeric', month: 'long', day: 'numeric'
      });
      const formattedTime = apptDate.toLocaleTimeString(undefined, {
        hour: '2-digit', minute: '2-digit'
      });
      apptItem.innerHTML = `
        <div class="appointment-header">Patient: ${appt.name}</div>
        <div class="appointment-details">
          <strong>Date:</strong> ${formattedDate}<br>
          <strong>Time:</strong> ${formattedTime}
        </div>
        <p class="appointment-reason"><strong>Reason:</strong> ${appt.reason}</p>
      `;
      appointmentList.appendChild(apptItem);
    });
  }

  // --- Data Display Functions ---
  function createStatsCards(userData) {
    const stats = [
      { title: "Total Patients", value: userData.totalSolved, label: "Patients Solved" },
      { title: "Acceptance Rate", value: `${userData.acceptanceRate}%`, label: "Success Rate" },
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

  function updateProgress(progressClass, labelId, solved, total) {
    const progressEle = document.querySelector(`.${progressClass}`);
    const labelEle = document.getElementById(labelId);
    
    const percentage = Math.min((solved / total) * 100, 100);
    const degree = `${percentage * 3.6}deg`;

    progressEle?.style.setProperty("--progress-degree", degree);
    if (labelEle) {
      labelEle.textContent = `${solved} Patients`;
    }
  }

  // --- Main Search Logic (with Simulated Data) ---
  searchButton?.addEventListener("click", () => {
    const username = usernameInput.value.trim().toLowerCase(); 

    if (username === "") {
      progressContainer.classList.add("hidden");
      statsCardsContainer.classList.add("hidden");
      feedbackContainer?.classList.add("hidden");
      appointmentContainer?.classList.add("hidden");
      alert("Please enter a doctor's username.");
      return;
    }

    loadingSpinner?.classList.remove("hidden");
    statsCardsContainer.innerHTML = ""; 

    setTimeout(() => {
      // Look up doctor in the simulated database
      const doctorData = doctorDatabase[username];

      loadingSpinner?.classList.add("hidden");

      // This logic checks if the name is in the database
      if (doctorData) {
        // --- DOCTOR FOUND: Use simulated data ---
        progressContainer.classList.remove("hidden");
        statsCardsContainer.classList.remove("hidden");
        feedbackContainer?.classList.remove("hidden");
        appointmentContainer?.classList.remove("hidden");
        
        updateProgress("easy-progress", "easy-level", doctorData.bp_patients, diseaseData[0].max);
        updateProgress("medium-progress", "medium-progress", doctorData.hb_patients, diseaseData[1].max);
        updateProgress("hard-progress", "hard-level", doctorData.diabetes_patients, diseaseData[2].max);
        updateProgress("asthma-progress", "asthma-level", doctorData.asthma_patients, diseaseData[3].max);
        updateProgress("heart-progress", "heart-level", doctorData.heart_patients, diseaseData[4].max);

        const totalSolved = 
          doctorData.bp_patients + 
          doctorData.hb_patients + 
          doctorData.diabetes_patients + 
          doctorData.asthma_patients + 
          doctorData.heart_patients;

        const userData = {
          totalSolved,
          acceptanceRate: doctorData.acceptanceRate,
          ranking: doctorData.ranking,
          reputation: doctorData.reputation,
        };

        createStatsCards(userData);

        if (!searchHistory.includes(username)) {
          searchHistory.push(username);
          updateSearchHistory();
        }

      } else {
        // --- DOCTOR NOT FOUND: Show error ---
        // This is why it does not work on "random names"
        progressContainer.classList.add("hidden");
        statsCardsContainer.classList.add("hidden");
        feedbackContainer?.classList.add("hidden");
        appointmentContainer?.classList.add("hidden");
        alert("Doctor not found. Please try again. (Try 'abhi123' or 'drsmith')");
      }
    }, 1500); 
  });

  usernameInput?.addEventListener("keypress", (e) => {
    if (e.key === "Enter") {
      searchButton.click();
    }
  });

  // --- Form Event Listeners ---
  feedbackForm?.addEventListener("submit", (e) => {
    e.preventDefault(); 
    const name = patientNameInput.value.trim();
    const rating = parseInt(patientRatingInput.value);
    const comment = patientCommentInput.value.trim();
    if (name && rating && comment) {
      const newFeedback = { name, rating, comment };
      patientFeedback.unshift(newFeedback); 
      saveFeedback();
      renderFeedback();
      feedbackForm.reset(); 
    } else {
      alert("Please fill out all feedback fields.");
    }
  });

  appointmentForm?.addEventListener("submit", (e) => {
    e.preventDefault();
    const name = apptPatientNameInput.value.trim();
    const date = apptDateInput.value;
    const time = apptTimeInput.value;
    const reason = apptReasonInput.value.trim();
    if (name && date && time && reason) {
      const dateTime = `${date}T${time}`;
      const newAppointment = { name, dateTime, reason };
      bookedAppointments.push(newAppointment);
      saveAppointments();
      renderAppointments();
      appointmentForm.reset();
    } else {
      alert("Please fill out all appointment fields.");
    }
  });

  // --- Initial Page Load Setup ---
  updateSearchHistory();
  updateThemeIcon(); 
  renderFeedback(); 
  renderAppointments(); 
});