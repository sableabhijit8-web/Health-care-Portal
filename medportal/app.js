document.addEventListener("DOMContentLoaded", function () {

  // ===== SIMULATED DATA =====
  const vitals = [
    { label: "Blood Pressure", value: "128/82", unit: "mmHg", trend: "down" },
    { label: "Heart Rate", value: "72", unit: "bpm", trend: "stable" },
    { label: "Blood Glucose", value: "142", unit: "mg/dL", trend: "up" },
    { label: "Weight", value: "176", unit: "lbs", trend: "down" },
  ];

  const appointments = [
    { doctor: "Dr. Sarah Chen", specialty: "Primary Care", date: "Feb 18, 2026", time: "9:30 AM", status: "upcoming" },
    { doctor: "Dr. James Patel", specialty: "Cardiology", date: "Feb 25, 2026", time: "2:00 PM", status: "upcoming" },
    { doctor: "Dr. Emily Russo", specialty: "Dermatology", date: "Jan 30, 2026", time: "11:00 AM", status: "completed" },
    { doctor: "Dr. Michael Tanaka", specialty: "Orthopedics", date: "Jan 15, 2026", time: "3:30 PM", status: "completed" },
    { doctor: "Dr. Lisa Nguyen", specialty: "Ophthalmology", date: "Feb 10, 2026", time: "10:00 AM", status: "cancelled" },
  ];

  const prescriptions = [
    { name: "Lisinopril", dosage: "10mg", frequency: "Once daily", refillDate: "Mar 5, 2026", refillsLeft: 3 },
    { name: "Metformin", dosage: "500mg", frequency: "Twice daily", refillDate: "Feb 20, 2026", refillsLeft: 1 },
    { name: "Atorvastatin", dosage: "20mg", frequency: "Once daily at bedtime", refillDate: "Apr 1, 2026", refillsLeft: 5 },
    { name: "Vitamin D3", dosage: "2000 IU", frequency: "Once daily", refillDate: "May 10, 2026", refillsLeft: 4 },
  ];

  const testResults = [
    { name: "Complete Blood Count (CBC)", date: "Feb 5, 2026", status: "normal", value: "Within range", range: "—" },
    { name: "HbA1c", date: "Feb 5, 2026", status: "abnormal", value: "6.8%", range: "< 5.7%" },
    { name: "Lipid Panel", date: "Feb 5, 2026", status: "normal", value: "LDL 98 mg/dL", range: "< 100 mg/dL" },
    { name: "Thyroid (TSH)", date: "Jan 20, 2026", status: "normal", value: "2.1 mIU/L", range: "0.4–4.0" },
    { name: "Chest X-Ray", date: "Feb 12, 2026", status: "pending", value: null, range: null },
  ];

  // ===== LOGIN LOGIC =====
  const loginForm = document.getElementById("login-form");
  if (loginForm) {
    const usernameInput = document.getElementById("username");
    const passwordInput = document.getElementById("password");
    const errorMessage = document.getElementById("error-message");

    loginForm.addEventListener("submit", function (e) {
      e.preventDefault();
      const username = usernameInput.value.trim();
      const password = passwordInput.value;

      if (username === "patient" && password === "pass123") {
        window.location.href = "index.html";
      } else {
        errorMessage.classList.remove("hidden");
      }
    });

    usernameInput.addEventListener("input", () => errorMessage.classList.add("hidden"));
    passwordInput.addEventListener("input", () => errorMessage.classList.add("hidden"));
  }

  // ===== DASHBOARD RENDERING =====
  const trendSymbols = { up: "&#9650;", down: "&#9660;", stable: "&#9644;" };
  const trendClass = { up: "trend-up", down: "trend-down", stable: "trend-stable" };

  // Vitals
  const vitalsGrid = document.getElementById("vitals-grid");
  if (vitalsGrid) {
    vitals.forEach(v => {
      vitalsGrid.innerHTML += `
        <div class="card vital-card">
          <p class="vital-label">${v.label}</p>
          <div class="vital-row">
            <p class="vital-value">${v.value} <span class="vital-unit">${v.unit}</span></p>
            <span class="${trendClass[v.trend]}">${trendSymbols[v.trend]}</span>
          </div>
        </div>`;
    });
  }

  // Appointments
  const aptList = document.getElementById("appointments-list");
  if (aptList) {
    appointments.slice(0, 4).forEach(a => {
      aptList.innerHTML += `
        <div class="list-item">
          <div class="list-item-left">
            <p class="name">${a.doctor}</p>
            <p class="sub">${a.specialty}</p>
            <p class="time">&#128339; ${a.date} · ${a.time}</p>
          </div>
          <span class="badge badge-${a.status}">${a.status.charAt(0).toUpperCase() + a.status.slice(1)}</span>
        </div>`;
    });
  }

  // Prescriptions
  const rxList = document.getElementById("prescriptions-list");
  if (rxList) {
    prescriptions.forEach(rx => {
      rxList.innerHTML += `
        <div class="list-item">
          <div class="list-item-left">
            <p class="name">${rx.name} — ${rx.dosage}</p>
            <p class="sub">${rx.frequency}</p>
          </div>
          <div class="list-item-right">
            <p class="sub">Refill: ${rx.refillDate}</p>
            <p class="bold">${rx.refillsLeft} refills left</p>
          </div>
        </div>`;
    });
  }

  // Test Results
  const statusIcons = { normal: "&#10004;", abnormal: "&#9888;", pending: "&#8987;" };
  const resultsList = document.getElementById("results-list");
  if (resultsList) {
    testResults.forEach(t => {
      const valueHtml = t.value ? `<p class="result-value">${t.value}</p>` : `<p class="result-range" style="font-style:italic">Pending</p>`;
      const rangeHtml = t.range ? `<p class="result-range">Ref: ${t.range}</p>` : "";
      resultsList.innerHTML += `
        <div class="result-item">
          <div class="result-left">
            <span class="result-icon ${t.status}">${statusIcons[t.status]}</span>
            <div>
              <p class="result-name">${t.name}</p>
              <p class="result-date">${t.date}</p>
            </div>
          </div>
          <div class="result-right">
            ${valueHtml}
            ${rangeHtml}
          </div>
        </div>`;
    });
  }

  // Next Appointment Banner
  const banner = document.getElementById("next-appointment-banner");
  const upcoming = appointments.filter(a => a.status === "upcoming");
  if (banner && upcoming.length > 0) {
    banner.innerHTML = `
      <div class="banner-icon">&#9829;</div>
      <div>
        <p class="banner-title">Next appointment</p>
        <p class="banner-sub">${upcoming[0].doctor} — ${upcoming[0].date} at ${upcoming[0].time}</p>
      </div>`;
  } else if (banner) {
    banner.style.display = "none";
  }
});
