#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void lesson1()
{
    char name[20];
    cout << "Як тебе звати?" << endl;
    cin >> name;
    cout << "Привіт, " << name << "!" << endl;

    Sleep(3000);
}


void Example1()
{
    int a, b;                                       //оголошуємо дві цілочисельні змінні
    cout << "Введіть два числа: ";                  //запитуємо у користувача їх введення
    cin >> a >> b;                                  //зчитуємо два введених числа у змінні a і b
    cout << "Ви ввели числа: " << a << " і " << b;  //виводимо повідомлення у вигляді, який вимагає умова
}

void Example2()
{
    srand(time(NULL));                              //запускаємо генератор випадкових чисел, тоді кожна генерація буде різною

    cout 
        << rand() % 10 << endl                      // генеруємо випадкові числа i розділяємо
        << rand() % 10 << endl                      // їх символом переходу на новий рядок
        << rand() % 10 << endl; 
}

void Example3()
{
    int t, h, m;
    cout << "Введіть часовий інтервал (у хв.): ";
    cin >> t;
    cout << t << " хвилин - це " << t / 60 << " год. " << t % 60 << "хв.";
}

void Example4()
{
    // Для scanf
    #include <stdio.h>

    // Через проблему пошкодженного компілятора Пі була вираженна вище.
    
    //усі змінні оголошуємо дійсного типу, щоб мати змогу обробляти будь-які введені користувачем вхідні дані
        float V, r1, r2, h;

    //запитуємо у користувача необхідні дані
    printf("Введіть висоту, радіус циліндра та радіус отвору, см: ");

    //зчитуємо введені користувачем значення у відповідні змінні
    //(функція scanf() змінена на scanf_s() через те, що компілятор вважає цю функцію небезпечною)
    scanf_s("%f %f %f", &h, &r1, &r2);

    //обчислюємо за формулою
    V = M_PI * h * (pow(r1, 2) - pow(r2, 2));

    //виводимо результат
    printf("Об\'єм порожнистого циліндру: % 6.2f см.куб.", V);
}


void Home_task1()
{
    int num1, num2, num3, summ;
    cout << "Введіть перше ціле число - "; cin >> num1;
    cout << "Введіть друге ціле число - "; cin >> num2;
    cout << "Введіть третє ціле число - "; cin >> num3;

    summ = num1 + num2 + num3;

    cout << "Сумма трьох введених цілих чисел: " << summ << endl;
         
}

void Home_task2()
{
    srand(time(NULL));

    cout << rand() % 100 << "  ";
    cout << rand() % 100 << "  ";
    cout << rand() % 100 << endl;
}

void Home_task3()
{
    float distance, fuelConsumption, fuelPrice;

    cout << "Введіть відстань до дачі (км): "; cin >> distance;
    cout << "Введіть витрати палива (літрів на 100 км пробігу): "; cin >> fuelConsumption;
    cout << "Введіть ціну літру палива (грн.): "; cin >> fuelPrice;

    float totalCost = ((distance * 2) / 100) * fuelConsumption * fuelPrice;


    // Округлення загальної вартості до двох знаків після коми
    totalCost = round(totalCost * 100) / 100;
    // Виведення результату
    cout << "Поїздка на дачу і назад обійдеться в " << totalCost << " грн." << endl;
}

void Home_task4()
{
    double a; // сторона квадрата
    cout << "Введіть сторону квадрата a: "; cin >> a;

    // Обчислення радіусів
    double R = a / sqrt(2); // радіус описаного кола
    double r = a / 2;       // радіус вписаного кола

    // Вивід результатів
    cout << "Радіус описаного кола R: " << R << endl;
    cout << "Радіус вписаного кола r: " << r << endl;
}

// Паненко Ян 

int Menu()
{
    while (true) {
        // Очищення консолі
        system("cls");

        // Вивід меню
        cout << "------------ Меню ------------" << endl;
        cout << "1. Виконати приклад 1" << endl;
        cout << "2. Виконати приклад 2" << endl;
        cout << "3. Виконати приклад 3" << endl;
        cout << "4. Виконати приклад 4" << endl;
        cout << "5. Виконати домашнє завдання 1" << endl;
        cout << "6. Виконати домашнє завдання 2" << endl;
        cout << "7. Виконати домашнє завдання 3" << endl;
        cout << "8. Виконати домашнє завдання 4" << endl;
        cout << "0. Вийти з програми" << endl;
        cout << "------------------------------" << endl;
        cout << endl;
        cout << "Введіть ваш вибір - ";
        int choice;
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1:
            Example1();
            break;
        case 2:
            Example2();
            break;
        case 3:
            Example3();
            break;
        case 4:
            Example4();
            break;
        case 5:
            Home_task1();
            break;
        case 6:
            Home_task2();
            break;
        case 7:
            Home_task3();
            break;
        case 8:
            Home_task4();
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            return 0; // Вихід з програми
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            Sleep(3000);
            continue;
        }

        cout << endl << endl;
        cout << "Натисніть будь-яку клавішу, щоб продовжити..." ;
        cin.ignore(); // Ігноруємо залишки вводу
        cin.get();    // Чекаємо, поки користувач натисне клавішу
    }
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*
    Example1();
    Example2();
    Example3();
    Example4();

    Home_task1();
    Home_task2();
    Home_task3();
    Home_task4();
    */

    Menu();
    


    return 0;
}
