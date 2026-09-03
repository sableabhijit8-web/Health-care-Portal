document.addEventListener('DOMContentLoaded', function() {
    lucide.createIcons();
    
    // Initialize mobile menu
    initMobileMenu();
    
    // Generate chemical cards
    generateChemicalCards();
    
    // Generate category cards
    generateCategoryCards();
    
    // Add smooth scrolling
    initSmoothScrolling();
});

// Mobile Menu Functionality
function initMobileMenu() {
    const mobileMenuBtn = document.getElementById('mobileMenuBtn');
    const mobileMenu = document.getElementById('mobileMenu');
    const menuIcon = document.getElementById('menuIcon');
    const closeIcon = document.getElementById('closeIcon');
    
    mobileMenuBtn.addEventListener('click', function() {
        const isOpen = mobileMenu.classList.contains('active');
        
        if (isOpen) {
            mobileMenu.classList.remove('active');
            menuIcon.style.display = 'block';
            closeIcon.style.display = 'none';
        } else {
            mobileMenu.classList.add('active');
            menuIcon.style.display = 'none';
            closeIcon.style.display = 'block';
        }
    });
    
    // Close mobile menu when clicking on nav links
    const mobileNavLinks = document.querySelectorAll('.mobile-nav-link');
    mobileNavLinks.forEach(link => {
        link.addEventListener('click', function() {
            mobileMenu.classList.remove('active');
            menuIcon.style.display = 'block';
            closeIcon.style.display = 'none';
        });
    });
}

// Chemical Data
const chemicalData = [
    {
        name: "Acetylsalicylic Acid",
        formula: "C₉H₈O₄",
        molWeight: "180.16 g/mol",
        category: "Pharmaceutical",
        hazardLevel: "low",
        description: "Common pain reliever and anti-inflammatory drug, widely known as Aspirin.",
        casNumber: "50-78-2"
    },
    {
        name: "Sodium Chloride",
        formula: "NaCl",
        molWeight: "58.44 g/mol",
        category: "Inorganic Salt",
        hazardLevel: "low",
        description: "Essential ionic compound, commonly known as table salt.",
        casNumber: "7647-14-5"
    },
    {
        name: "Sulfuric Acid",
        formula: "H₂SO₄",
        molWeight: "98.08 g/mol",
        category: "Mineral Acid",
        hazardLevel: "high",
        description: "Highly corrosive strong mineral acid with wide industrial applications.",
        casNumber: "7664-93-9"
    },
    {
        name: "Ethanol",
        formula: "C₂H₆O",
        molWeight: "46.07 g/mol",
        category: "Alcohol",
        hazardLevel: "medium",
        description: "Simple alcohol compound used in beverages, fuel, and as a solvent.",
        casNumber: "64-17-5"
    },
    {
        name: "Caffeine",
        formula: "C₈H₁₀N₄O₂",
        molWeight: "194.19 g/mol",
        category: "Alkaloid",
        hazardLevel: "medium",
        description: "Natural stimulant compound found in coffee, tea, and many plants.",
        casNumber: "58-08-2"
    },
    {
        name: "Benzene",
        formula: "C₆H₆",
        molWeight: "78.11 g/mol",
        category: "Aromatic",
        hazardLevel: "high",
        description: "Fundamental aromatic hydrocarbon, important industrial solvent and precursor.",
        casNumber: "71-43-2"
    }
];

// Category Data
const categoryData = [
    {
        id: 'organic',
        name: 'Organic Compounds',
        description: 'Carbon-based molecular structures and derivatives',
        icon: 'leaf',
        count: '25,000+',
        color: 'text-green-600'
    },
    {
        id: 'inorganic',
        name: 'Inorganic Compounds',
        description: 'Minerals, salts, acids, and metal compounds',
        icon: 'atom',
        count: '15,000+',
        color: 'text-blue-600'
    },
    {
        id: 'polymers',
        name: 'Polymers & Plastics',
        description: 'Synthetic and natural polymer materials',
        icon: 'building-2',
        count: '5,000+',
        color: 'text-purple-600'
    },
    {
        id: 'solvents',
        name: 'Solvents',
        description: 'Industrial and laboratory solvents',
        icon: 'droplets',
        count: '3,000+',
        color: 'text-cyan-600'
    },
    {
        id: 'reagents',
        name: 'Lab Reagents',
        description: 'Analytical and synthetic reagents',
        icon: 'flask-conical',
        count: '8,000+',
        color: 'text-orange-600'
    },
    {
        id: 'catalysts',
        name: 'Catalysts',
        description: 'Reaction catalysts and accelerators',
        icon: 'zap',
        count: '2,000+',
        color: 'text-yellow-600'
    }
];

// Generate Chemical Cards
function generateChemicalCards() {
    const grid = document.getElementById('chemicalsGrid');
    
    chemicalData.forEach((chemical, index) => {
        const card = createChemicalCard(chemical);
        card.style.animationDelay = `${index * 0.1}s`;
        grid.appendChild(card);
    });
    
    // Re-initialize icons for the new elements
    lucide.createIcons();
}

// Create Chemical Card Element
function createChemicalCard(chemical) {
    const card = document.createElement('div');
    card.className = 'card';
    
    card.innerHTML = `
        <div class="card-header">
            <div class="chemical-card-header">
                <div class="chemical-info">
                    <h3 class="card-title">${chemical.name}</h3>
                    <div class="chemical-formula">${chemical.formula}</div>
                </div>
                <div class="badge">${chemical.category}</div>
            </div>
        </div>
        
        <div class="card-content">
            <div class="properties-grid">
                <div>
                    <div class="property-label">Mol. Weight:</div>
                    <div class="property-value">${chemical.molWeight}</div>
                </div>
                ${chemical.casNumber ? `
                <div>
                    <div class="property-label">CAS:</div>
                    <div class="property-value" style="font-family: monospace; font-size: 0.75rem;">${chemical.casNumber}</div>
                </div>
                ` : ''}
            </div>
            
            <p class="chemical-description">${chemical.description}</p>
            
            <div class="card-footer">
                <div class="hazard-info">
                    <i data-lucide="alert-triangle" style="width: 1rem; height: 1rem;"></i>
                    <span class="hazard-badge hazard-${chemical.hazardLevel}">
                        ${chemical.hazardLevel.toUpperCase()} RISK
                    </span>
                </div>
                
                <div class="card-actions">
                    <button class="btn btn-scientific btn-icon">
                        <i data-lucide="eye"></i>
                    </button>
                    <button class="btn btn-scientific btn-icon">
                        <i data-lucide="info"></i>
                    </button>
                </div>
            </div>
        </div>
    `;
    
    return card;
}

// Generate Category Cards
function generateCategoryCards() {
    const grid = document.getElementById('categoriesGrid');
    
    categoryData.forEach((category, index) => {
        const card = createCategoryCard(category);
        card.style.animationDelay = `${index * 0.1}s`;
        grid.appendChild(card);
    });
    
    // Re-initialize icons for the new elements
    lucide.createIcons();
}

// Create Category Card Element
function createCategoryCard(category) {
    const card = document.createElement('div');
    card.className = 'card category-card';
    
    card.innerHTML = `
        <div class="card-header">
            <div class="category-icon">
                <i data-lucide="${category.icon}" style="width: 2rem; height: 2rem;"></i>
            </div>
            <h3 class="card-title">${category.name}</h3>
        </div>
        
        <div class="card-content">
            <p style="color: var(--muted-foreground); margin-bottom: 1rem;">
                ${category.description}
            </p>
            
            <div class="category-count">${category.count}</div>
            
            <button class="btn btn-scientific category-btn">
                Explore Category
                <i data-lucide="arrow-right" style="margin-left: 0.5rem; width: 1rem; height: 1rem;"></i>
            </button>
        </div>
    `;
    
    return card;
}

// Smooth Scrolling for Navigation Links
function initSmoothScrolling() {
    const navLinks = document.querySelectorAll('a[href^="#"]');
    
    navLinks.forEach(link => {
        link.addEventListener('click', function(e) {
            e.preventDefault();
            
            const targetId = this.getAttribute('href');
            const targetSection = document.querySelector(targetId);
            
            if (targetSection) {
                const offsetTop = targetSection.offsetTop - 80; // Account for fixed navbar
                
                window.scrollTo({
                    top: offsetTop,
                    behavior: 'smooth'
                });
            }
        });
    });
}

// Search Functionality
document.addEventListener('DOMContentLoaded', function() {
    const searchInput = document.querySelector('.search-input');
    const searchButton = document.querySelector('.btn-hero');
    
    function performSearch() {
        const query = searchInput.value.trim();
        if (query) {
            console.log('Searching for:', query);
            // Here you would typically send a request to your backend API
            alert(`Searching for: ${query}\n\nThis would connect to your chemical database API.`);
        }
    }
    
    searchButton.addEventListener('click', performSearch);
    
    searchInput.addEventListener('keypress', function(e) {
        if (e.key === 'Enter') {
            performSearch();
        }
    });
});

// Add some interactive effects
document.addEventListener('DOMContentLoaded', function() {
    // Add hover effects to cards
    const cards = document.querySelectorAll('.card');
    
    cards.forEach(card => {
        card.addEventListener('mouseenter', function() {
            this.style.transform = 'translateY(-2px)';
        });
        
        card.addEventListener('mouseleave', function() {
            this.style.transform = 'translateY(0)';
        });
    });
    
    // Add click handlers for chemical card buttons
    document.addEventListener('click', function(e) {
        if (e.target.closest('.btn-scientific')) {
            const button = e.target.closest('.btn-scientific');
            const card = button.closest('.card');
            const chemicalName = card.querySelector('.card-title').textContent;
            
            if (button.querySelector('[data-lucide="eye"]')) {
                alert(`Viewing detailed information for: ${chemicalName}`);
            } else if (button.querySelector('[data-lucide="info"]')) {
                alert(`Showing additional data for: ${chemicalName}`);
            }
        }
        
        if (e.target.closest('.category-btn')) {
            const card = e.target.closest('.card');
            const categoryName = card.querySelector('.card-title').textContent;
            alert(`Exploring category: ${categoryName}`);
        }
    });
});