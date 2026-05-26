type Observer<T> = (value: T) => void;
type TransformFn<T, R> = (value: T) => R;
type PredicateFn<T> = (value: T) => boolean;

interface SearchResult {
    id: number;
    title: string;
    category: string;
}

 // Базовий клас Observable (Спостережуване значення)
 // Реалізує патерн Publisher/Subscriber у функціональному стилі
class Observable<T> {
    private subscribers: Observer<T>[] = [];

    constructor(private subscribeFn?: (observer: Observer<T>) => void) {}

    subscribe(observer: Observer<T>): void {
        this.subscribers.push(observer);
        if (this.subscribeFn) {
            this.subscribeFn(observer);
        }
    }

    next(value: T): void {
        this.subscribers.forEach(sub => sub(value));
    }

    map<R>(fn: TransformFn<T, R>): Observable<R> {
        return new Observable<R>((observer) => {
            this.subscribe((value) => observer(fn(value)));
        });
    }

    filter(fn: PredicateFn<T>): Observable<T> {
        return new Observable<T>((observer) => {
            this.subscribe((value) => {
                if (fn(value)) observer(value);
            });
        });
    }

    debounce(delay: number): Observable<T> {
        let timeoutId: any = null;
        return new Observable<T>((observer) => {
            this.subscribe((value) => {
                clearTimeout(timeoutId);
                timeoutId = setTimeout(() => observer(value), delay);
            });
        });
    }
}

const compose = <T>(...fns: Function[]) => (initialValue: T) =>
    fns.reduceRight((value, fn) => fn(value), initialValue);

const filterByQuery = (query: string) => (items: SearchResult[]): SearchResult[] => {
    const lowerQuery = query.toLowerCase().trim();
    if (!lowerQuery)
        return [];
    return items.filter(item => item.title.toLowerCase().indexOf(lowerQuery) !== -1);
};

const mapToHtmlStrings = (items: SearchResult[]): string[] => {
    return items.map(item => `
        <div style="padding: 10px; border-bottom: 1px solid #ccc;">
            <strong>${item.title}</strong> <small style="color: gray;">(${item.category})</small>
        </div>
    `);
};


const reduceToSingleString = (htmlStrings: string[]): string => {
    return htmlStrings.reduce((acc, html) => acc + html, "");
};

const transformDataPipeline = (query: string) => compose(
    reduceToSingleString,
    mapToHtmlStrings,
    filterByQuery(query)
);

const DATABASE: SearchResult[] = [
    { id: 1, title: "Вступ до JavaScript та екосистеми", category: "JavaScript" },
    { id: 2, title: "Чисті функції та іммутабельність в JS", category: "Функціональне програмування" },
    { id: 3, title: "Функції вищого порядку в TypeScript", category: "JavaScript" },
    { id: 4, title: "Реактивні потоки даних та HOF оператори", category: "Реактивне програмування" },
    { id: 5, title: "Опанування каррінгу та композиції функцій", category: "Функціональне програмування" },
    { id: 6, title: "Конфігурація ядра Linux та кастомні модулі", category: "Адміністрування Linux" },
    { id: 7, title: "Оптимізація продуктивності ігор на EndeavourOS Arch Linux", category: "Адміністрування Linux" },
    { id: 8, title: "Налаштування драйверів NVIDIA на Linux системах", category: "Адміністрування Linux" },
    { id: 9, title: "Оптимізація Docker-контейнерів для Node.js проектів", category: "Девопс та Інфраструктура" },
    { id: 10, title: "Оркестрація сервісів за допомогою Podman та Docker Compose", category: "Девопс та Інфраструктура" },
    { id: 11, title: "Створення та деплой серверів у контейнерах", category: "Девопс та Інфраструктура" },
    { id: 12, title: "Хостинг та оптимізація серверів modded Minecraft на Linux", category: "Ігровий Хостинг" },
    { id: 13, title: "Розробка модпаків та менеджмент пам'яті Java в Minecraft", category: "Ігровий Хостинг" },
    { id: 14, title: "Робота з асинхронним кодом: Promises та Async/Await", category: "JavaScript" },
    { id: 15, title: "Створення інтерфейсів на Qt Widgets в C++", category: "Програмування C++" },
    { id: 16, title: "Керування пам'яттю та вказівники в мові C++", category: "Програмування C++" },
    { id: 17, title: "Побудова архітектури додатків на C# та .NET Core", category: "Програмування C#" },
    { id: 18, title: "Організація бази знань та автоматизація в Obsidian", category: "Продуктивність" },
    { id: 19, title: "Генерація академічних звітів з Markdown у PDF через Pandoc", category: "Продуктивність" }
];


function main() {
    function setupInteractiveUI() {
        const appContainer = document.getElementById("app") || document.body;

        appContainer.innerHTML = `
        <div style="font-family: Arial, sans-serif; max-width: 500px; margin: 40px auto; padding: 20px; border: 1px solid #ddd; border-radius: 8px; box-shadow: 0 4px 6px rgba(0,0,0,0.1);">
            <h2>Реактивний пошук (FRP Демо)</h2>
            <input type="text" id="live-search" placeholder="Введіть запит..." style="width: 100%; padding: 12px; font-size: 16px; border: 1px solid #ccc; border-radius: 4px; box-sizing: border-box; margin-bottom: 15px;">
            <div id="search-results" style="background: #fafafa; border-radius: 4px; max-height: 300px; overflow-y: auto;">
                <div style="padding: 10px; color: gray;">Введіть щось для старту пошуку...</div>
            </div>
        </div>
    `;

        const inputElement = document.getElementById("live-search") as HTMLInputElement;
        const resultsContainer = document.getElementById("search-results") as HTMLDivElement;

        if (!inputElement || !resultsContainer) return;

        // Створюємо потік подій введення
        const inputStream = new Observable<string>();

        inputElement.addEventListener("input", (e) => {
            const target = e.target as HTMLInputElement;
            inputStream.next(target.value);
        });

        inputStream
            .map(text => text.trim())
            .debounce(350)
            .subscribe((query) => {
                console.log(`[FRP Stream] Отримано очищений запит: "${query}"`);

                if (!query) {
                    resultsContainer.innerHTML = "";
                    resultsContainer.style.borderColor = "transparent";
                    return;
                }

                const pipeline = transformDataPipeline(query);
                const finalHtml = pipeline(DATABASE);

                if (finalHtml) {
                    resultsContainer.innerHTML = finalHtml;
                    resultsContainer.style.border = "1px solid #e2e8f0";
                } else {
                    resultsContainer.innerHTML = `<div style="padding: 15px; color: #e53e3e; text-align: center; font-size: 14px; font-weight: 500;">Нічого не знайдено</div>`;
                    resultsContainer.style.border = "1px solid #e2e8f0";
                }
            });
    }

    if (typeof window !== "undefined") {
        window.addEventListener("DOMContentLoaded", setupInteractiveUI);
        if (document.readyState === "complete" || document.readyState === "interactive") {
            setupInteractiveUI();
        }
    }
}

main()