function summarizeNumbers(numbers) {
    // Обробка крайнього випадку: порожній масив
    if (numbers.length === 0) {
        return { count: 0, sum: 0, evenCount: 0, max: undefined, category: "empty" };
    }

    let sum = 0;
    let evenCount = 0;
    let max = numbers[0];

    // Класичний цикл for для ручних обчислень
    for (let i = 0; i < numbers.length; i++) {
        const num = numbers[i];
        sum += num;

        if (num % 2 === 0) {
            evenCount++;
        }

        if (num > max) {
            max = num;
        }
    }

    const category = sum > 0 ? "positive" : "non-positive";

    return {
        count: numbers.length,
        sum: sum,
        evenCount: evenCount,
        max: max,
        category: category
    };
}

console.log(summarizeNumbers([4, 7, 2, 9]))
// { count: 4, sum: 22, evenCount: 2, max: 9, category: "positive" }
console.log(summarizeNumbers([]))
// { count: 0, sum: 0, evenCount: 0, max: undefined, category: "empty" }

