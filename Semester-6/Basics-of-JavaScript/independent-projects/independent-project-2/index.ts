function task1() {
    // 1. Написати цикл,
    // який виводить на екран таблицю множення для числа 5
    let num = 5

    // Варіант виконання 1
    console.log(`Таблиця множення на ${num}:`)
    for (let i = 1; i <= 10; i++) {
            console.log(`${i} * ${num} = ${i * num}`)
    }

    // Варіант виконання 2
    // console.log(`\nТаблиця множення на ${num}:`)
    // let row = '#'.padEnd(3, ' ')
    // for (let i = 1; i <= num; i++) {
    //     row += i.toString().padEnd(3, ' ')
    // }
    // console.log(row)
    //
    // for (let i = 1; i <= num; i++) {
    //     row = i.toString().padEnd(3, ' ')
    //     for (let j = 1; j <= num; j++) {
    //         row += (i * j).toString().padEnd(3, ' ')
    //     }
    //     console.log(row)
    // }
}

function task2() {
    // Написати цикл,
    // який виводить на екран всі числа, які діляться на 3 або на 5, від 1 до 50.
    const YELLOW = "\x1b[33m";
    const RESET = "\x1b[0m";

    const startPoint: number = 1;
    const endPoint: number = 50;

    const dividers = [3, 5];
    let results: number[] = [];

    for (let i = startPoint; i <= endPoint; i++) {
        for (const iElement of dividers) {
            if (i % iElement == 0) {
                results.push(i);
                break
            }
        }
    }

    //console.log(`Числа які діляться на ${(() => {let str = ""; for (const divider of dividers) {str += divider + " ";} return str.trim(); })()}: (${YELLOW}${results.join(' ')}${RESET});`);

    console.log(`Числа від ${startPoint} до ${endPoint}, які діляться на ${dividers.join(', ')}: (${YELLOW}${results.join(' ')}${RESET});`);

    //console.log(results.join(' '))

}

function task3 () {
    // Написати програму,
    // яка перевіряє, чи є введене число паліндромом
    // (тобто читається однаково зліва направо і справа наліво).
    // 12321

    const polyndrom = "12321";

    let endId = polyndrom.length;
    let polyndromLow = polyndrom.toLowerCase();
    for (let startId = 0; startId < polyndrom.length; startId++) {
        endId--;
        if (polyndromLow[startId] != polyndromLow[endId]) {
            console.log(`Рядок "${polyndrom}" не є поліндромом!`);
            break;
        }
        if (startId >= endId) {
            console.log(`Рядок "${polyndrom}" є поліндромом!`);
            break;
        }
    }

    // Або можна так:
    // if (polyndrom.toLowerCase() == polyndrom.toLowerCase().split('').reverse().join(''))
    //     console.log(`Рядок "${polyndrom}" є поліндромом!`);
    // else
    //     console.log(`Рядок "${polyndrom}" не є поліндромом!`);
}

task1()
task2()
task3()