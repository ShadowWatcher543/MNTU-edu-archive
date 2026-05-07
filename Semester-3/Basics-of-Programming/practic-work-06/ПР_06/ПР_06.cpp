#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;


int Example1() {

    const float M_PI = 3.141592653589793;
    float x, y;
    int k;

    cout << "Введіть х: ";
    cin >> x;
    cout << "Виберіть k (від 1 до 5): ";
    cin >> k;

    switch (k) {
        case 1: { y = pow(x + 1, 1. / 5); break; }
        case 2: { y = tan(cos(x) + M_PI / 2); break; }
        case 3: { y = exp(2 * x * x) + sqrt(fabs(1 - x)); break; }
        case 4: { y = pow(sin(x * x + 3), 2); break; }
        case 5: { y = cos(3 * x * x); break; }
        default: { 
            cout << "Помилка!";
            return 1;                                               // Додав фихід бо інакше при спробі виведення y буде помилка.
        } 
    }
    cout << "y = " << y;

    return 0;
}

int Example2() {

    float a, c, h, S;
    int n;

    cout << "Який елемент вам відомий:\n1-катет, 2-гіпотенуза, 3 - висота, 4 - площа? ";
    cin >> n;

    switch (n) {
        case 1: {
            cout << "Введіть катет: ";
            cin >> a;

            c = a * sqrt(2);
            h = c / 2;
            S = a * a / 2;
            break; 
        }
        case 2: {
            cout << "Введіть гіпотенузу: ";
            cin >> c;

            a = c / sqrt(2);
            h = c / 2;
            S = c * c / 4;
            break; 
        }
        case 3: {
            cout << "Введіть висоту: ";
            cin >> h;

            c = 2 * h;
            a = c / sqrt(2);
            S = c * c / 4;
            break; 
        }
        case 4: {
            cout << "Введіть площу: ";
            cin >> S;

            a = sqrt(2 * S);
            c = sqrt(4 * S);
            h = 2 * S / c;
            break; 
        }
        default:
            cout << "Помилка!";
            return 1;
    }

    cout << "Катет " << a << endl;
    cout << "Гіпотенуза " << c << endl;
    cout << "Висота " << h << endl;
    cout << "Площа " << S << endl;

    return 0;
}

int Example3() {

    int m, a, b;
    cout << "Введіть число гривень (1-99): ";
    cin >> m;

    if (!(m > 0 && m < 100)) { // додав опрацювання виходу для коректної роботи меню 
        cout << "Помилка!!!";
        return 1;
    }

    //розбиваємо введене число окремо на першу цифру
    a = m / 10;
    //і другу цифру
    b = m % 10;
    //випадок, коли перша цифра «1» – особливий, опрацьовуємо його окремо
    if (a == 1)
    {
        //число визначаємо по другій цифрі
        switch (b)
        {
        case 0: cout << "десять"; break;
        case 1: cout << "одинадцять"; break;
        case 2: cout << "дванадцять"; break;
        case 3: cout << "тринадцять"; break;
        case 4: cout << "чотирнадцять"; break;
        case 5: cout << "п’ятнадцять"; break;
        case 6: cout << "шістнадцять"; break;
        case 7: cout << "сімнадцять"; break;
        case 8: cout << "вісімнадцять"; break;
        case 9: cout << "дев’ятнадцять"; break;
        }
        //слово «гривня» в цьому випадку має однаковий відмінок
        cout << " гривень";
    }
    //для всіх інших випадків (крім першої цифри «1»)
    else
    {
        //виводимо окремо опис десятків

        switch (a)
        {
        //якщо десятків 0, то виводити тут нічого не треба, а випадок з 1 десятком ми вже опрацювали вище.Тому починаємо з 2 десятків
        case 2: cout << "двадцять "; break;
        case 3: cout << "тридцять "; break;
        case 4: cout << "сорок "; break;
        case 5: cout << "п’ятдесят "; break;
        case 6: cout << "шістдесят "; break;
        case 7: cout << "сімдесят "; break;
        case 8: cout << "вісімдесят "; break;
        case 9: cout << "дев’яносто "; break;
        }
        // і окремо опис одиниць
        switch (b)
        {
        case 1: cout << "одна "; break;
        case 2: cout << "дві "; break;
        case 3: cout << "три "; break;
        case 4: cout << "чотири "; break;
        case 5: cout << "п’ять "; break;
        case 6: cout << "шість "; break;
        case 7: cout << "сім "; break;
        case 8: cout << "вісім "; break;
        case 9: cout << "дев’ять "; break;
        }
        //лишається додати слово «гривня» в правильній формі, вона залежить від останньої цифри : якщо вона дорівнює 1 – то «гривня», якщо 2, 3, 4 – «гривні», у всіх інших випадках(5, 6, 7, 8, 9, 0) – «гривень»
        switch (b)
        {
            case 1: cout << "гривня"; break;
            case 2:
            case 3:
            case 4: cout << "гривні"; break;
            default: cout << "гривень"; break;
        }    
    }
    return 0;
}

void Example4() {

    int year, animal, color;
    cout << "Enter year: ";
    cin >> year;
    //новий цикл тварин починається кожні 12 років,
    animal = year % 12;
    //а новий цикл кольору – кожні 10 років
    color = year % 10;
    cout << endl << "It is year of ";
    //перебираємо кольори: кожні два роки колір змінюється
    switch (color)
    {
    case 0:
    case 1: { cout << "white "; break; }

    case 2:
    case 3: { cout << "blue "; break; }
    case 4:
    case 5: { cout << "green "; break; }
    case 6:
    case 7: { cout << "red "; break; }
    case 8:
    case 9: { cout << "yellow "; break; }
    }
    //далі перебираємо тварин
    switch (animal)
    {
    case 0: { cout << "monkey"; break; }
    case 1: { cout << "cock"; break; }
    case 2: { cout << "dog"; break; }
    case 3: { cout << "pig"; break; }
    case 4: { cout << "rat"; break; }
    case 5: { cout << "bull"; break; }
    case 6: { cout << "tiger"; break; }
    case 7: { cout << "rabbit"; break; }
    case 8: { cout << "dragon"; break; }
    case 9: { cout << "snake"; break; }
    case 10: { cout << "horse"; break; }
    case 11: { cout << "sheep"; break; }
    }
    cout << endl;
}

int Home_task1() {

    const float e = 2.71828182846, g = 9.8;
    float x, result;
    int l;

    cout << "Обчислити:" << endl;
    
    cout << "      / sqrt(x) + e^x          при L = 1 " << endl;
    cout << "      | ln|x| + 0.8            при L = 2 " << endl;
    cout << " y =  < x^2 : lg^2|x|          при L = 3 " << endl;
    cout << "      | xcos^2(x) + sqrt(x)    при L = 4 " << endl;
    cout << "      \\ e^(0.8x) + |x|       при L = 5 " << endl;
    cout << endl;
    
    cout << "Введіть L від 1 до 5: "; cin >> l;
    cout << endl;

    cout << "Введіть X: "; cin >> x;
    cout << endl;

    cout << "Використовувані змінні: " << endl;
    cout << " e = 2.7182818284; g = 9.8; x = " << x << "; L = " << l << ";" << endl;
    cout << endl;


    switch (l)
    {
    case 1:
        result = sqrt(x) + pow(e, x);
        break;
    case 2:
        result = log(abs(x)) + 0.8;
        break;
    case 3:
        result = pow(x, 2) / pow(log(abs(x)), 2);
        break;
    case 4:
        result = (x * pow(cos(x), 2)) + sqrt(x);
        break;
    case 5:
        result = pow(e, (0.8 * x)) + abs(x);
        break;
    default:
        cout << "Помилка вибору варіанта!" << endl;
        return 1;
        break;
    }

    cout << "y = " << result << ";" << endl;

    return 0;
}

int Home_task2() {

    const float M_PI = 3.141592653589793;
    double value, R, D, L, S;
    int element;
    
    cout << "Введіть номер відомого елемента (1 радіус, 2 діаметр, 3 довжина, 4 площа): "; cin >> element;
    cout << endl;
    
    if (element != 1 && element != 2 && element != 3 && element != 4) {
        cout << "Невірний номер елемента!" << endl;
        return 1;
    }
    
    cout << "Введіть значення цього елемента: "; cin >> value; 
    cout << endl;
    
    switch (element) {
        case 1: // Радіус R
            R = value;
            D = 2 * R;
            L = 2 * M_PI * R;
            S = M_PI * pow(R, 2);
            break;
        case 2: // Діаметр D
            D = value;
            R = D / 2;
            L = 2 * M_PI * R;
            S = M_PI * pow(R, 2);
            break;
        case 3: // Довжина L
            L = value;
            R = L / (2 * M_PI);
            D = 2 * R;
            S = M_PI * pow(R, 2);
            break;
        case 4: // Площа S
            S = value;
            R = sqrt(S / M_PI);
            D = 2 * R;
            L = 2 * M_PI * R;
            break;
        default:
            cout << "Невірний номер елемента!" << endl;
            return 1;
        }

        // Вивести значення всіх елементів
        cout << "Радіус R: " << R << endl;
        cout << "Діаметр D: " << D << endl;
        cout << "Довжина L: " << L << endl;
        cout << "Площа S: " << S << endl;

        return 0;
}

int Home_task3() {

    int minutes, tens, ones;

    cout << "Введіть кількість хвилин (0-59): "; cin >> minutes;
    cout << endl;

    if (!(minutes >= 0 && minutes < 60)) { // Перевірка коректності введеного числа
        cout << "Помилка!!!";
        return 1;
    }

    // Розбиваємо введене число на десятки та одиниці
    tens = minutes / 10;
    ones = minutes % 10;

    // Якщо число від 10 до 19, обробляємо окремо
    if (tens == 1) {
        switch (ones) {
        case 0: cout << "десять"; break;
        case 1: cout << "одинадцять"; break;
        case 2: cout << "дванадцять"; break;
        case 3: cout << "тринадцять"; break;
        case 4: cout << "чотирнадцять"; break;
        case 5: cout << "п’ятнадцять"; break;
        case 6: cout << "шістнадцять"; break;
        case 7: cout << "сімнадцять"; break;
        case 8: cout << "вісімнадцять"; break;
        case 9: cout << "дев’ятнадцять"; break;
        }
        // Для чисел від 10 до 19 форма слова "хвилина" завжди "хвилин"
        cout << " хвилин";
    }
    else {
        // Виводимо десятки для чисел від 20 до 59
        switch (tens) {
        case 2: cout << "двадцять "; break;
        case 3: cout << "тридцять "; break;
        case 4: cout << "сорок "; break;
        case 5: cout << "п’ятдесят "; break;
        }

        // Виводимо одиниці (якщо є)
        switch (ones) {
        case 0: if (tens == 0) cout << "нуль "; break;
        case 1: cout << "одна "; break;
        case 2: cout << "дві "; break;
        case 3: cout << "три "; break;
        case 4: cout << "чотири "; break;
        case 5: cout << "п’ять "; break;
        case 6: cout << "шість "; break;
        case 7: cout << "сім "; break;
        case 8: cout << "вісім "; break;
        case 9: cout << "дев’ять "; break;
        }

        // Підбираємо правильну форму слова "хвилина"
        switch (ones) {
        case 1: cout << "хвилина"; break;
        case 2:
        case 3:
        case 4: cout << "хвилини"; break;
        default: cout << "хвилин"; break;
        }
    }

    return 0;
}

int Menu() {

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
            case 'a':
                cout << "Home Work #1" << "\n\n";
                //Home_task1();
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

    //Menu();
   

    int c = 10;
    int x = (c == 3) ? 2 + c : c - 2;
    cout << x;


    return 0;
}
