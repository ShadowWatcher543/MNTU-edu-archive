// БАЗОВІ ТА НАСЛІДУВАНІ КЛАСИ

// Базовий клас для всіх тварин у магазині
class Pet {
    // Інкапсуляція: приватні поля
    #id: string;
    #name: string;
    #species: string;
    #age: number;
    #price: number;
    #isVaccinated: boolean;
    #image: string;

    constructor(name: string, species: string, age: number, price: number, image: string) {
        this.#id = Math.random().toString(36).substring(2, 9);
        this.#name = name;
        this.#species = species;
        this.#age = age;
        this.#price = price;
        this.#isVaccinated = false;
        this.#image = image;
    }

    // Геттери та сеттери
    get id(): string { return this.#id; }
    get name(): string { return this.#name; }
    get species(): string { return this.#species; }
    get age(): number { return this.#age; }
    get price(): number { return this.#price; }
    get isVaccinated(): boolean { return this.#isVaccinated; }
    get image(): string { return this.#image; }

    set isVaccinated(value: boolean) { this.#isVaccinated = value; }

    // Поліморфний метод для отримання специфічних деталей тварини
    getDetails(): string {
        return `Вік: ${this.#age} р., Щеплення: ${this.#isVaccinated ? "Так" : "Ні"}`;
    }
}

// Клас Собака, що наслідує Pet

class Dog extends Pet {
    #breed: string;
    #isTrained: boolean;

    constructor(name: string, age: number, price: number, breed: string, isTrained: boolean, image: string) {
        super(name, "Dog", age, price, image);
        this.#breed = breed;
        this.#isTrained = isTrained;
    }

    get breed(): string { return this.#breed; }
    get isTrained(): boolean { return this.#isTrained; }

    getDetails(): string {
        return `${super.getDetails()}, Порода: ${this.#breed}, Дресирований: ${this.#isTrained ? "Так" : "Ні"}`;
    }
}

// Клас Кіт, що наслідує Pet
class Cat extends Pet {
    #color: string;
    #isIndoor: boolean;

    constructor(name: string, age: number, price: number, color: string, isIndoor: boolean, image: string) {
        super(name, "Cat", age, price, image);
        this.#color = color;
        this.#isIndoor = isIndoor;
    }

    get color(): string { return this.#color; }
    get isIndoor(): boolean { return this.#isIndoor; }

    getDetails(): string {
        return `${super.getDetails()}, Забарвлення: ${this.#color}, Домашній: ${this.#isIndoor ? "Так" : "Ні"}`;
    }
}

// Клас Птах, що наслідує Pet
class Bird extends Pet {
    #canTalk: boolean;

    constructor(name: string, age: number, price: number, canTalk: boolean, image: string) {
        super(name, "Bird", age, price, image);
        this.#canTalk = canTalk;
    }

    get canTalk(): boolean { return this.#canTalk; }

    getDetails(): string {
        return `${super.getDetails()}, Вміє говорити: ${this.#canTalk ? "Так" : "Ні"}`;
    }
}



// КЛАС КЕРУВАННЯ МАГАЗИНОМ (PET STORE)
interface SalesRecord {
    petId: string;
    petName: string;
    species: string;
    price: number;
    buyer: string;
    date: Date;
}

class PetStore {
    #inventory: Pet[] = [];
    #salesHistory: SalesRecord[] = [];

    constructor() {
        this.loadFromLocalStorage();
    }

    // Статичний утилітарний метод для форматування валюти
    static formatCurrency(amount: number): string {
        return `${amount} грн`;
    }

    get inventory(): Pet[] { return this.#inventory; }
    get salesHistory(): SalesRecord[] { return this.#salesHistory; }

    addPet(pet: Pet): void {
        this.#inventory.push(pet);
        this.#saveToLocalStorage();
    }

    vaccinate(petId: string): boolean {
        for (let i = 0; i < this.#inventory.length; i++) {
            if (this.#inventory[i].id === petId) {
                this.#inventory[i].isVaccinated = true;
                this.#saveToLocalStorage();
                return true;
            }
        }
        return false;
    }

    sellPet(petId: string, buyer: string): boolean {
        let targetIndex = -1;
        for (let i = 0; i < this.#inventory.length; i++) {
            if (this.#inventory[i].id === petId) {
                targetIndex = i;
                break;
            }
        }

        if (targetIndex === -1) return false;

        const pet = this.#inventory[targetIndex];

        const finalPrice = this.#calculateFinalPrice(pet.price);

        this.#salesHistory.push({
            petId: pet.id,
            petName: pet.name,
            species: pet.species,
            price: finalPrice,
            buyer: buyer,
            date: new Date()
        });

        // Ручне видалення з інвентарю через зсув масиву
        const updatedInventory: Pet[] = [];
        for (let i = 0; i < this.#inventory.length; i++) {
            if (i !== targetIndex) {
                updatedInventory.push(this.#inventory[i]);
            }
        }
        this.#inventory = updatedInventory;
        this.#saveToLocalStorage();
        return true;
    }

    // Приватний метод для розрахунку вартості
    #calculateFinalPrice(basePrice: number): number {
        return basePrice * 1.05;
    }

    // Алгоритм сумісності: повертає тварин, які підходять за видом
    getCompatiblePets(speciesQuery: string): Pet[] {
        const compatible: Pet[] = [];
        for (let i = 0; i < this.#inventory.length; i++) {
            if (this.#inventory[i].species.toLowerCase() === speciesQuery.toLowerCase()) {
                compatible.push(this.#inventory[i]);
            }
        }
        return compatible;
    }

    #saveToLocalStorage(): void {
        const inventoryData = this.#inventory.map(pet => ({
            id: pet.id,
            name: pet.name,
            species: pet.species,
            age: pet.age,
            price: pet.price,
            isVaccinated: pet.isVaccinated,
            image: pet.image,
            breed: pet instanceof Dog ? pet.breed : undefined,
            isTrained: pet instanceof Dog ? pet.isTrained : undefined,
            color: pet instanceof Cat ? pet.color : undefined,
            isIndoor: pet instanceof Cat ? pet.isIndoor : undefined,
            canTalk: pet instanceof Bird ? pet.canTalk : undefined
        }));

        localStorage.setItem("pet_store_inventory", JSON.stringify(inventoryData));
        localStorage.setItem("pet_store_sales", JSON.stringify(this.#salesHistory));
    }

    loadFromLocalStorage(): void {
        const localInventory = localStorage.getItem("pet_store_inventory");
        const localSales = localStorage.getItem("pet_store_sales");

        if (localInventory) {
            try {
                const rawData = JSON.parse(localInventory);
                this.#inventory = rawData.map((item: any) => {
                    let pet: Pet;
                    if (item.species === "Dog") {
                        pet = new Dog(item.name, item.age, item.price, item.breed, item.isTrained, item.image);
                    } else if (item.species === "Cat") {
                        pet = new Cat(item.name, item.age, item.price, item.color, item.isIndoor, item.image);
                    } else if (item.species === "Bird") {
                        pet = new Bird(item.name, item.age, item.price, item.canTalk, item.image);
                    } else {
                        pet = new Pet(item.name, item.species, item.age, item.price, item.image);
                    }
                    Object.defineProperty(pet, 'id', { value: item.id });
                    pet.isVaccinated = item.isVaccinated;
                    return pet;
                });
            } catch (e) {
                console.error("Error parsing inventory", e);
            }
        }

        if (localSales) {
            try {
                this.#salesHistory = JSON.parse(localSales);
            } catch (e) {
                console.error("Error parsing sales history", e);
            }
        }
    }
}


// ІНІЦІАЛІЗАЦІЯ ТА ОБРОБКА UI ЗАХОДІВ

const store = new PetStore();

// Ініціалізація інвентарю магазину
if (store.inventory.length === 0 && store.salesHistory.length === 0) {
    store.addPet(new Dog("Барон", 1, 6000, "Хаскі", true, "/assets/images/photo-1531804055935-76f44d7c3621.jpg"));
    store.addPet(new Dog("Альф", 3, 4500, "Мопс", false, "/assets/images/photo-1517849845537-4d257902454a.jpg"));
    store.addPet(new Cat("Мурчик", 2, 2000, "Рудий", true, "/assets/images/photo-1514888286974-6c03e2ca1dba.jpg"));
    store.addPet(new Cat("Сіма", 1, 2500, "Сірий", true, "/assets/images/photo-1573865526739-10659fec78a5.jpg"));
    store.addPet(new Bird("Кеша", 4, 1500, true, "/assets/images/photo-1452570053594-1b985d6ea890.jpg"));
}

function updateCatalog() {
    const speciesFilter = (document.getElementById("filter-species") as HTMLSelectElement)?.value || "all";
    const ageFilter = parseInt((document.getElementById("filter-age") as HTMLInputElement)?.value) || Infinity;

    const grid = document.getElementById("catalog-grid");
    const statsCount = document.getElementById("stats-count");
    const statsSales = document.getElementById("stats-sales");
    const salesTable = document.getElementById("sales-table-body");

    if (!grid) return;

    grid.innerHTML = "";
    let visibleCount = 0;

    for (let i = 0; i < store.inventory.length; i++) {
        const pet = store.inventory[i];

        if (speciesFilter !== "all" && pet.species !== speciesFilter) continue;
        if (pet.age > ageFilter) continue;

        visibleCount++;

        const card = document.createElement("div");
        card.style.border = "1px solid #e2e8f0";
        card.style.borderRadius = "8px";
        card.style.overflow = "hidden";
        card.style.background = "white";
        card.style.boxShadow = "0 2px 4px rgba(0,0,0,0.02)";

        card.innerHTML = `
            <img src="${pet.image}" style="width: 100%; height: 160px; object-fit: cover; background: #e2e8f0;">
            <div style="padding: 15px;">
                <h3 style="margin: 0 0 5px 0;">${pet.name}</h3>
                <span style="font-size: 12px; background: #ebf8ff; color: #2b6cb0; padding: 2px 6px; border-radius: 4px; font-weight: bold;">${pet.species}</span>
                <p style="font-size: 13px; color: #4a5568; margin: 10px 0;">${pet.getDetails()}</p>
                <div style="font-weight: bold; color: #2f855a; font-size: 16px; margin-bottom: 12px;">
                    ${PetStore.formatCurrency(pet.price)}
                </div>
                <div style="display: flex; gap: 8px;">
                    <button class="vaccinate-btn" data-id="${pet.id}" style="flex: 1; padding: 6px; font-size: 12px; background: #e2e8f0; border: 0; border-radius: 4px; cursor: pointer;" ${pet.isVaccinated ? "disabled" : ""}>
                        ${pet.isVaccinated ? "✓ Вакциновано" : "Вакцинувати"}
                    </button>
                    <button class="buy-btn" data-id="${pet.id}" style="flex: 1; padding: 6px; font-size: 12px; background: #48bb78; color: white; border: 0; border-radius: 4px; cursor: pointer; font-weight: bold;">
                        Купити
                    </button>
                </div>
            </div>
        `;
        grid.appendChild(card);
    }

    if (visibleCount === 0) {
        grid.innerHTML = `<div style="grid-column: 1/-1; text-align: center; color: gray; padding: 40px;">Тварин за вказаними критеріями не знайдено</div>`;
    }

    // Оновлення статистики
    if (statsCount) statsCount.innerText = store.inventory.length.toString();
    if (statsSales) statsSales.innerText = store.salesHistory.length.toString();

    // Оновлення таблиці продажів
    if (salesTable) {
        if (store.salesHistory.length === 0) {
            salesTable.innerHTML = `<tr><td colspan="4" style="padding: 10px; color: gray; text-align:center;">Операцій ще не проводилось</td></tr>`;
        } else {
            salesTable.innerHTML = "";
            for (let i = 0; i < store.salesHistory.length; i++) {
                const record = store.salesHistory[i];
                const tr = document.createElement("tr");
                tr.style.borderBottom = "1px solid #cbd5e0";
                tr.innerHTML = `
                    <td style="padding: 8px; font-weight:600;">${record.buyer}</td>
                    <td style="padding: 8px;">${record.petName}</td>
                    <td style="padding: 8px;"><span style="font-size:11px; background:#edf2f7; padding:2px 5px; border-radius:4px;">${record.species}</span></td>
                    <td style="padding: 8px; color:#2f855a; font-weight:bold;">${PetStore.formatCurrency(record.price)}</td>
                `;
                salesTable.appendChild(tr);
            }
        }
    }
}

function setupEventHandlers() {
    document.getElementById("filter-species")?.addEventListener("change", updateCatalog);
    document.getElementById("filter-age")?.addEventListener("input", updateCatalog);

    // Слухаємо кліки через делегування подій на рівні всього body контейнера
    document.body.addEventListener("click", (e) => {
        const target = e.target as HTMLElement;

        if (target.classList.contains("vaccinate-btn")) {
            const id = target.getAttribute("data-id");
            if (id) {
                store.vaccinate(id);
                updateCatalog();
            }
        }

        if (target.classList.contains("buy-btn")) {
            const id = target.getAttribute("data-id");
            if (id) {
                const buyerName = prompt("Введіть ім'я покупця для оформлення договору:");
                if (buyerName && buyerName.trim() !== "") {
                    store.sellPet(id, buyerName.trim());
                    updateCatalog();
                } else if (buyerName !== null) {
                    alert("Помилка валідації форми: Ім'я покупця обов'язкове!");
                }
            }
        }
        if (target.classList.contains("reset-storage-btn")) {
            if (confirm("Ви впевнені, що хочете повністю скинути сховище та повернути початкових тварин?")) {
                localStorage.removeItem("pet_store_inventory");
                localStorage.removeItem("pet_store_sales");
                location.reload();
            }
        }
    });
}

if (document.readyState === "loading") {
    window.addEventListener("DOMContentLoaded", () => {
        updateCatalog();
        setupEventHandlers();
    });
} else {
    updateCatalog();
    setupEventHandlers();
}