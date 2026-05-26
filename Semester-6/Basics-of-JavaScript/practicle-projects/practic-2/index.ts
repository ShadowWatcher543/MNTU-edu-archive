// Напишіть функцію, яка приймає масив чисел та повертає масив
// з квадратами цих чисел. Наприклад, [1, 2, 3, 4] -> [1, 4, 9, 16].
function getSquares(arr: number[]): number[] {
    let squared: number[] = [];

    for (let i = 0; i < arr.length; i++) {
        squared.push(arr[i] * arr[i]);
    }

    return squared;
}

// Напишіть функцію, яка приймає масив чисел та повертає
// найбільше число з масиву. Наприклад, [3, 5, 1, 8, 4] -> 8.
function getMaximum(arr: number[]): number {
     let max = arr[0];

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Напишіть функцію, яка приймає масив рядків та повертає
// масив, що містить лише унікальні рядки з вхідного масиву.
// Наприклад, ["a", "b", "a", "c", "b"] -> ["a", "b", "c"].
function getUniqueStrings(arr: string[]): string[] {
    const unique: string[] = [];

    for (let i = 0; i < arr.length; i++) {
        let isDuplicate = false;

        for (let j = 0; j < unique.length; j++) {
            if (arr[i] === unique[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            unique.push(arr[i]);
        }
    }

    return unique;
}



console.log("=== Старт тестування функцій ===");

// Тест завдання №1
const inputNumbers1 = [1, 2, 3, 4];
const result1 = getSquares(inputNumbers1);
console.log(`Завдання №1: Квадрати чисел [${inputNumbers1.join(', ')}] -> [${result1.join(', ')}]`);

// Тест завдання №2
const inputNumbers2 = [3, 5, 1, 8, 4];
const result2 = getMaximum(inputNumbers2);
console.log(`Завдання №2: Найбільше число з масиву [${inputNumbers2.join(', ')}] -> ${result2}`);

// Тест завдання №3
const inputStrings = ["a", "b", "a", "c", "b"];
const result3 = getUniqueStrings(inputStrings);
console.log(`Завдання №3: Унікальні рядки з [${inputStrings.join(', ')}] -> [${result3.join(', ')}]`);

console.log("=== Тестування завершено ===");
