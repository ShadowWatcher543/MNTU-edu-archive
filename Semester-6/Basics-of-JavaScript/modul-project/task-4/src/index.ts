// Інтерфейс для структури об'єкта завдання
interface ITask {
    id: string;
    text: string;
    done: boolean;
    toggle(): void;
}

// Клас окремого завдання
class Task implements ITask {
    public id: string;
    public text: string;
    public done: boolean;

    constructor(id: string, text: string) {
        this.id = id;
        this.text = text;
        this.done = false;
    }

    toggle(): void {
        this.done = !this.done;
    }
}

// Клас логіки списку
class TodoList {
    public tasks: ITask[];

    constructor() {
        this.tasks = [];
    }

    add(text: string): ITask {
        const id: string = Date.now() + Math.random().toString(36).substr(2, 5); // унікальний id
        const newTask = new Task(id, text);
        this.tasks.push(newTask);
        return newTask;
    }

    remove(id: string): void {
        // Видалення через класичний пошук індексу та зсув
        let index = -1;
        for (let i = 0; i < this.tasks.length; i++) {
            if (this.tasks[i].id === id) {
                index = i;
                break;
            }
        }
        if (index !== -1) {
            this.tasks.splice(index, 1);
        }
    }

    getActive(): ITask[] {
        return this.tasks.filter(t => !t.done);
    }
}

// --- DOM інтеграція та логіка інтерфейсу ---

const todo = new TodoList();

// Кастинг типів DOM-елементів, щоб уникнути помилок доступу до value або innerHTML
const taskInput = document.getElementById("taskInput") as HTMLInputElement;
const addBtn = document.getElementById("addBtn") as HTMLButtonElement;
const taskList = document.getElementById("taskList") as HTMLUListElement;

// Функція рендерингу інтерфейсу
function render(): void {
    taskList.innerHTML = "";

    for (let i = 0; i < todo.tasks.length; i++) {
        const task = todo.tasks[i];
        const li = document.createElement("li");

        li.textContent = task.text;
        li.dataset.id = task.id;
        li.style.cursor = "pointer";

        if (task.done) {
            li.style.textDecoration = "line-through";
            li.style.color = "#a0aec0";
        }
        taskList.appendChild(li);
    }
}

// Додавання нового завдання по кліку
addBtn.addEventListener("click", (): void => {
    const text: string = taskInput.value.trim();

    if (text === "") return; // Валідація порожнього рядка
    todo.add(text);
    taskInput.value = "";
    render();
});

// Делегування подій: клік по списку міняє статус done конкретного завдання
taskList.addEventListener("click", (event: MouseEvent): void => {
    const targetLi = event.target as HTMLElement;

    if (targetLi.tagName === "LI") {
        const id = targetLi.dataset.id;

        // Шукаємо об'єкт класу Task та викликаємо його метод toggle
        for (let i = 0; i < todo.tasks.length; i++) {
            if (todo.tasks[i].id === id) {
                todo.tasks[i].toggle();
                break;
            }
        }
        render();
    }
});