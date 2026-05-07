#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;


void Example1()
{
    //оголошуємо усі необхідні змінні. Ініціалізуємо ті змінні, значення яких задані за умовою
        float R = 12, A, t = 7, U;
    //запитуємо у користувача значення, якого не вистачає
    cout << "Введіть напругу U->"; cin >> U;
    //після цього можемо виконати обчислення за формулою
    A = pow(U, 2) / R * t;
    //виводимо отриманий результат на екран
    cout << "Робота електричного струму A= " << A << endl;
}

void Example2()
{
    //оскільки величина ε0 є фізичною константою, то й в програмі оголосимо її теж константою
    const double E0 = 8.85e-12;
    //для всіх інших величин оголошуємо звичайні змінні
    double d, S, C, E = 2.8;
    //запитуємо у користувача значення, яких не вистачає
    cout << "Введіть відстань між пластинами d->"; cin >> d;
    cout << "Введіть площу пластини S->"; cin >> S;
    // виконуємо обчислення
    C = (E0 * E * S) / d;
    //виводимо результат
    cout << "Ємність конденсатора C=" << C << endl;
}

void Example3()
{
    float x, y; //оголошення змінних дійсного типу
    cout << "Введіть x->"; cin >> x;

    //y = ((0.2 * (x * x) - x) / ((sqrt(3) + x) * (1 + (2 * x)))) + (2 * pow(x - 1, 3) / (pow(sin(x), 2) + 1));
    y = (0.2 * x * x - x) / ((sqrt(3) + x) * (1 + 2 * x)) + 2 * pow(x - 1, 3) / (pow(sin(x), 2) + 1);

    cout << "Результат y=" << y;
}

void Example4()
{
    const float m = 7.4;
    float b, x, p, y;

    cout << "Введіть b->";
    cin >> b;
    x = atan(b * b + sqrt(b + m));
    p = cos(pow(exp(fabs(b - x)) - log10(fabs(x - b)), 2));
    y = pow(pow(sin(m * p - M_PI), 2) / (b * x + p), 1. / 3);
    cout << "x = " << x << endl;
    cout << "p = " << p << endl;
    cout << "y = " << y;
}

void Example5()
{
    const float b = 2;
    float k, t, a, y;
    printf("Введіть k = ");
    scanf_s("%f", &k);
    printf("\nk = %1.2f", k);
    t = b * b + pow(k, 2);
    printf("\nt = %1.2f", t);
    a = sqrt(b + t);
    printf("\na = %1.2f", a);
    y = pow(sin(a * a + pow(b, 2)), 4);
    printf("\ny = %5.2e", y);
}

void Example6()
{
    double a, x, y;
    cout << "Введіть x->"; cin >> x;
    cout << "Введіть a->"; cin >> a;

    y = pow(pow(sin(pow(x, 1.5 * a)), 3) + pow(atan(sqrt(fabs(x + sqrt(a * x)))), 3), 4) / (log(fabs(x) + exp(sqrt(pow(log10(pow(0.5 * x * x, 3)), 3)))) + x * x);
    cout << "y=" << y;
}

void Home_task1()
{
    const double e = 2.718281828459045;
    const double Pi = 3.1415926535897931;
    double x, y, a, b, c;

    cout << "Введіть x - "; cin >> x;
    cout << "Введіть y - "; cin >> y;

    a = log10(abs( (y - sqrt(abs(x))) * (x - (y/(x + ((x*x)/4))))));
    b = pow(e, x) - (((y * y) + (12 * x * y) - (3 * x * x)) / ((18 * y) - 1));
    c = ((Pi + cos(x * y)) / (sin(y) - (x * Pi))) + (6 / x);

    cout << "Значення a: " << a << endl;
    cout << "Значення b: " << b << endl;
    cout << "Значення c: " << c << endl;
}

void Home_task2()
{
    const double Pi = 3.1415926535897931;
    double R, LenCirut, AreaCircut;

    cout << "Введіть круга (R) - "; cin >> R;

    LenCirut = 2 * Pi * R;
    AreaCircut = Pi * pow(R, 2);

    cout << "Довжина кола з радіусом " << R << " дорівнює: " << LenCirut << endl;
    cout << "Площа круга з радіусом " << R << " дорівнює: " << AreaCircut << endl;

}

void Home_task3()
{
    double x, y, a, b, c;
    x = 1.52;
    c = 5;

    b = sqrt(x);
    a = cbrt(abs(b + c));
    y = (a * pow(sin(b), 2)) + (b * cos(pow(a, 2)));

    cout << "Значення y - " << y << endl;
}



// Паненко Ян 

int Menu()
{
    while (true) {

        system("cls");

        cout << "ПР_04" << endl;
        //cout << endl;

        cout << "------------ Меню ------------" << endl;
        cout << "1. Виконати приклад 1" << endl;
        cout << "2. Виконати приклад 2" << endl;
        cout << "3. Виконати приклад 3" << endl;
        cout << "4. Виконати приклад 4" << endl;
        cout << "5. Виконати приклад 5" << endl;
        cout << "6. Виконати приклад 6" << endl;
        cout << endl;
        cout << "A. Виконати домашнє завдання 1" << endl;
        cout << "B. Виконати домашнє завдання 2" << endl;
        cout << "C. Виконати домашнє завдання 3" << endl;
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

    Menu();

    return 0;
}
