function Task1() {
    let name, age, isStudent, favoriteColorl

    name = "Іван";
    age = 20;
    isStudent = true;
    favoriteColorl = "синій";

    console.log(`Name: ${name}, age: ${age}, isStudent: ${isStudent}, favoriteColorl: ${favoriteColorl} `)
}

function Task2() {
    let num1 = 10, num2 = 20;

    let sum, difference, product, quotient;

    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;

    console.log(`Sum: ${sum}, difference: ${difference}, product: ${product}, quotient: ${quotient}`)
}

function Task3() {
    let firstName, lastName, fullName;
    firstName = "Yan";
    lastName = "Panenko";

    fullName = firstName + " " + lastName;
    console.log(fullName);
}

function Task4() {
    let numberAsString, number, stringNumber;
    numberAsString = "123";

    number = Number(numberAsString)
    //console.log(typeof number);       // Виведе number

    stringNumber = String(number);
    //console.log(typeof stringNumber);     // Виведе string


    console.log(`Number: ${number}, stringNumber: ${stringNumber}`)
}

function Task5() {
    let isSunny, isRaining;
    isSunny = true
    isRaining = false

    if (isSunny && isRaining) {
        console.log("Sunny and Raining")
    }   else {
        console.log("NOT Sunny and Raining")
    }
    if (isSunny || isRaining) {
        console.log("Sunny or Raining")
    } else {
        console.log("NOT Sunny or Raining")
    }
}

function Task6() {
    // Створіть змінні x, y, z з різними типами даних (число, рядок, масив).
    // Використовуйте оператор typeof для визначення типу даних кожної змінної.
    // Виведіть результати на консоль.
    let x, y, z;
    x = 1;
    y = "2"
    z = [1, 2, 3];
    console.log(`x: ${typeof x}, y: ${typeof y}, z: ${typeof z}`)

    // Створіть змінну age та перевірте, чи є користувач повнолітнім (18 років).
    let age = 18;
    if (age >= 18) {
        console.log(`Користувач є повнолітнім.`)
    } else {
        console.log(`Користувач є неповнолітнім.`)
    }

    // Створіть змінну price та перевірте, чи є вона числом.
    let price = 120.50;

    if (typeof price === "number" && !isNaN(price)) {
        console.log("Змінна price є валідним числом.");
    } else {
        console.log("Змінна price НЕ є числом.");
    }


    // Створіть змінну email та перевірте, чи є вона валідною адресою електронної пошти.
    let email = "test.user@gmail.com";

    let atIndex = email.indexOf("@");
    let dotIndex = email.lastIndexOf("."); // Шукаємо останню крапку (для домену)

    // Перевіряємо умови:
    // - '@' існує (індекс > 0, тобто не на самому початку)
    // - '.' існує і йде щонайменше через один символ після '@' (dotIndex > atIndex + 1)
    // - '.' не є останнім символом рядка (dotIndex < email.length - 1)
    if (atIndex > 0 && dotIndex > atIndex + 1 && dotIndex < email.length - 1) {
        console.log("Email є валідним.");
    } else {
        console.log("Некоректний формат Email.");
    }


    // Створіть змінну password та перевірте, чи відповідає вона заданим вимогам (довжина, символи).
    let password = "SecurePass123";

    let hasNumber = false;
    let hasUpperCase = false;

    // Перебираємо кожен символ у паролі
    for (let char of password) {
        if (char !== " " && !isNaN(Number(char))) {
            hasNumber = true;
        }
        else if (char === char.toUpperCase() && char !== char.toLowerCase()) {
            hasUpperCase = true;
        }
    }

    // Фінальна перевірка всіх трьох вимог
    if (password.length >= 8 && hasNumber && hasUpperCase) {
        console.log("Пароль відповідає всім вимогам.");
    } else {
        console.log("Пароль занадто слабкий.");
    }

}

Task1()
Task2()
Task3()
Task4()
Task5()
Task6()