#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;


void Example1()
{
    //оголошуємо цілочисельну змінну для зберігання числа
    int x;
    cout << "Введіть ненульове число:";
    //зчитуємо число введене користувачем
    cin >> x;
    //перевіряємо, якщо воно більше 0, то виводимо «Додатне»
    if (x > 0) cout << "Додатне" << endl;
    //інакше виводимо «Від’ємне»
    else cout << "Від’ємне" << endl;
}

void Example2()
{
    float x, y;

    cout << "Введіть число: ";
    cin >> x;
    //перевіряємо, чи потрапляє введене користувачем значення в область допустимих значень функції
    if (x - 7 >= 0 && sqrt(x - 7) - 2 != 0)
    {
        //якщо так, то обчислюємо і виводимо результат
        y = 3 / (sqrt(x - 7) - 2);
        cout << "y = " << y << endl;
    }
    //якщо ні – виводимо відповідне повідомлення
    else cout << "Обчислити неможливо" << endl;
}

void Example3()
{
    float y, x;
    cout << "Введіть x ";

    cin >> x;
    if (x <= -4)
        y = x * x - 8;
    else
        if (x < 0)
            y = 3 * x - 2;
        else
            y = 2 - x;
    cout << "y = " << y;
}

void Example4()
{
    float I, T, L;
    cout << "Введіть період T і довжину електричного кола L:";
    cin >> T >> L;
    if ((L >= 0) && (L <= 1. / 3)) I = sin(L * T) - cos(L / T);
    else
        if (L <= 2. / 3) I = sin(T / L) + cos(1. / (T * L));
        else
            if (L <= 1)
                I = exp(L * T) * (pow(sin(1. / (T * L)), 2) -
                    pow(cos(L * T), 2));
    cout << "Сила струму = " << I;
}

void Example5()
{
    //оголосимо дійсні змінні для опорів окремих резисторів та всього електричного кола
    float r1, r2, R;
    //вид з’єднання будемо зберігати у цілочисельній змінній
    int p;
    cout << "Введіть опори резисторів r1 і r2: ";
    cin >> r1 >> r2;
    cout << "Оберіть вид з’єднання (1-послідовне, 2-паралельне): ";
    cin >> p;
    if (p == 1)
        R = r1 + r2;
    else if (p == 2)
        R = r1 * r2 / (r1 + r2);
    else R = 0;
    if (R) cout << "Опір кола становить " << R;
    else cout << "Невірний вид з’єднання!";
}

void Example6()
{
    //координати точки
    float x, y;
    //номер чверті
    int n;
    cout << "Введіть координати точки x і y ";
    cin >> x >> y;
    if ((x == 0) || (y == 0))
        n = 0;
    else
        if (x > 0 && y > 0) n = 1;
        else
            if (x < 0 && y>0) n = 2;
            else
                if (x < 0 && y < 0) n = 3;
                else
                    n = 4;
    if (n) cout << "Точка лежить в " << n << " чверті";
    else cout << "Точка лежить на осі";
}

void Example7()
{
    //оголошуємо необхідні змінні: коефіцієнти, дискримінант, корені рівняння
    double a, b, c, D, x1, x2;
    cout << "Введіть коефіцієнти квадратного рівняння a, b, c ";
    cin >> a >> b >> c;
    //обчислюємо дискримінант
    D = b * b - 4 * a * c;
    //якщо дискримінант від’ємний, то дійсних коренів немає
    if (D < 0) cout << "Дійсних коренів немає!";
    //інакше обчислюємо корені і виводимо їх
    else
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Корені рівняння: x1=" << x1 << " x2=" << x2;
    }
}

void Home_task1()
{
    float a, b, c;
    cout << "Введіть три дійсні числа, що визначають довжину сторін трикутника: "; cin >> a >> b >> c;

    // Перевірка умови існування трикутника
    if ((a + b > c) && (a + c > b) && (b + c > a)) 
        cout << "Триутник зі сторонами " << a << " " << b << " " << c << " " << "існує." << endl;
    else 
        cout << "Триутник зі сторонами " << a << " " << b << " " << c << " " << "не існує." << endl;
    
}

void Home_task2()
{
    float x1, x2, y1, y2, xA, yA;

    cout << "Попередження якщо число дійсне то записувати його портібно через \".\"" << endl << endl;
    cout << "Введіть кординати лівої верхньої вершини прямокутника у форматі X Y: "; cin >> x1 >> y1;
    cout << "Введіть кординати правої нижньої вершини прямокутника у форматі X Y: "; cin >> x2 >> y2;
    cout << "Введіть кординати точки А у форматі X Y: "; cin >> xA >> yA;

    cout << endl;

    if ((xA >= x1 && xA <= x2) && (yA <= y1 && yA >= y2))
        cout << "Точка А(" << xA << ", " << yA << ") належить заданому прямокутнику.";
    else
        cout << "Точка А(" << xA << ", " << yA << ") не належить заданому прямокутнику.";
}

void Home_task3()
{
    float num1, num2, quadSum, sumQuad;

    cout << "Попередження якщо число дійсне то записувати його портібно через \".\"" << endl << endl;

    cout << "Введіть перше число: "; cin >> num1;
    cout << "Введіть друге число: "; cin >> num2;

    cout << endl;

    quadSum = pow(num1 + num2, 2);
    sumQuad = (pow(num1, 2) + pow(num2, 2));

    if (sumQuad != quadSum) {
        if (sumQuad > quadSum)
            cout << "Сумма квадратів БІЛЬШЕ ніж квадрат сумми." << endl;
        else 
            cout << "Квадрат сумми БІЛЬШЕ ніж сумма квадратів." << endl;
    } else
        cout << "Сумма квадратів та квадрат сумми введених чисел ОДНАКОВІ." << endl;
}

void Home_task4()
{
    const double a = 1.5, b = -1.7, z = 1.2;
    double x, result;

    cout << "Обчислення:" << endl; 
    cout << "   a = " << a << ", b = " << b << ", z = " << z << ";" << endl;
    cout << endl;

    cout << "       / a * sin^2(x) + cos(zx)       при x < ln(a) " << endl;
    cout << "   y = | cos^3(a + zx)                при ln(a) <= x <= b " << endl;
    cout << "       \\ sqrt(2.5*a^3 + (b - zx^2)^6) при x > b " << endl;

    cout << endl;

    cout << "Введіть значення змінної X: "; cin >> x;

    if (x < log(a))
        result = (a * pow(sin(x), 2)) + cos(z * x);
    else if (log(a) <= x && x <= b)
        result = pow(cos(a + (z * x)), 3);
    else if (x > b)
        result = sqrt( (2.5 * pow(a, 3)) + pow(b - (z * pow(x, 2)), 6));

    cout << "Результат обчислення - " << result << endl;

}

int Menu()
{
    while (true) {
        // Паненко Ян
        system("cls");

        cout << "ПР_05" << endl;
        //cout << endl;

        cout << "------------ Меню ------------" << endl;
        cout << "1. Виконати приклад 1" << endl;
        cout << "2. Виконати приклад 2" << endl;
        cout << "3. Виконати приклад 3" << endl;
        cout << "4. Виконати приклад 4" << endl;
        cout << "5. Виконати приклад 5" << endl;
        cout << "6. Виконати приклад 6" << endl;
        cout << "7. Виконати приклад 7" << endl;
        cout << endl;
        cout << "A. Виконати домашнє завдання 1" << endl;
        cout << "B. Виконати домашнє завдання 2" << endl;
        cout << "C. Виконати домашнє завдання 3" << endl;
        cout << "D. Виконати домашнє завдання 4" << endl;
        cout << endl;
        cout << "Q. Вийти з програми" << endl;
        cout << "------------------------------" << endl;
        cout << endl;
        cout << "Введіть ваш вибір - ";

        char choice; cin >> choice;

        choice = tolower(choice);

        system("cls");

        switch (choice) {
        case '1':
            cout << "Example #1" << "\n\n";
            Example1();
            break;
        case '2':
            cout << "Example #2" << "\n\n";
            Example2();
            break;
        case '3':
            cout << "Example #3" << "\n\n";
            Example3();
            break;
        case '4':
            cout << "Example #4" << "\n\n";
            Example4();
            break;
        case '5':
            cout << "Example #5" << "\n\n";
            Example5();
            break;
        case '6':
            cout << "Example #6" << "\n\n";
            Example6();
            break;
        case '7':
            cout << "Example #7" << "\n\n";
            Example7();
            break;
        case 'a':
            cout << "Home Work #1" << "\n\n";
            Home_task1();
            break;
        case 'b':
            cout << "Home Work #2" << "\n\n";
            Home_task2();
            break;
        case 'c':
            cout << "Home Work #3" << "\n\n";
            Home_task3();
            break;
        case 'd':
            cout << "Home Work #4" << "\n\n";
            Home_task4();
            break;
        case 'q':
            cout << "Вихід з програми." << endl;
            return 0; // Вихід з програми
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            break;
        }

        cout << endl << endl;
        cout << "Натисніть  клавішу Enter, щоб продовжити...";
        cin.ignore(); // Ігноруємо залишки вводу
        cin.get();    // Чекаємо, поки користувач натисне клавішу
    }
}





int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Menu();
    int x = 0;

    switch (x)
    {
    case 0: 
        x = 1; 
        cout << x; 
        break;

    case 3: 
        cout << x; break;

    default: 
        x = 2;
        cout << x;

    }

    

    return 0;
}
