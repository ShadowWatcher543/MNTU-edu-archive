function task1() {
    //Написати програму, яка перевіряє, чи є введене користувачем число парним чи непарним.
    // - Показуємо prompt, в якому питаємо число, від користувача
    // - Перевіряємо чи є число парним?
    // - Результат виводимо через alert

    let input: string, num: number, result: string;

    input = prompt("Завдання №1: \nВведіть число для перевірки на парність.")

    num = parseInt(input)
    if (num % 2 != 0 || num == 0) {
        result = "не парним"
    } else {
        result = "парним"
    }

    alert(`Число ${num} є ${result}!`)
}

function task2() {
    // Написати програму, яка рахує суму чисел від 1 до 100,
    // виводить кінцеву суму, та на кожній ітерації, за допомогою console.
    const start = 1
    const end = 100
    let sum: number = 0;

    for (let i = start; i <= end; i++) {
        sum += i;
        console.log(`${i}) ${sum}`)
    }
    alert(`Завдання №2:\nCума чисел від ${start} до ${end}:\n${sum}`)


    //alert(`Завдання №2:\nСпосіб 1\nCума чисел від 1 до 100: \n${sum}`)

    // Взагалі ось кращий спосіб підрахунку:
    // sum = (2 * start + 1 * (end-1)) / 2 * end
    // alert(`Завдання №2:\nСпосіб 2\nCума чисел від 1 до 100: \n${sum}`)
}

function task3() {
    //Написати програму, яка виводить числа від 1 до 100
    const start = 1
    const end = 100
    let resultarr: string[] = []
    let result: string;

    for (let i = start; i <= end; i++) {
        resultarr.push(i.toString())
    }
    result = resultarr.join(' ')
    alert(`Числа від від ${start} до ${end}: \n${result}`)
}

while (true) {
    task1()
    task2()
    task3()

    let result = confirm("Повторити виконання коду? Скасувати - Ні/Ок - Так");
    if (result == false) {
        break
    }
}