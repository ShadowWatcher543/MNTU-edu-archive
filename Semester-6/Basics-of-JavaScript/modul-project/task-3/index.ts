function createApiClient(baseUrl: string) {
    // Приватна змінна лічильника завдяки замиканню
    let requestCount = 0;

    return {
        async get(path: string) {
            requestCount++; // Збільшуємо лічильник при кожному виклику
            try {
                const response = await fetch(baseUrl + path);
                if (!response.ok) {
                    throw new Error("Помилка сервера");
                }
                return await response.json();
            } catch (error) {
                // Відловлюємо будь-які проблеми з мережею або парсингом
                return { error: "Запит не вдався" };
            }
        },
        getRequestCount() {
            return requestCount;
        }
    };
}

const api = createApiClient("https://jsonplaceholder.typicode.com");
const user = await api.get("/users/1"); // об'єкт користувача
const posts = await api.get("/posts"); // масив постів

console.log(api.getRequestCount())
// 2