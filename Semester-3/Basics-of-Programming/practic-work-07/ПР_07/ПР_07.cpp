//#include <iostream>
//#include <windows.h>
//#include <math.h>
//
//using namespace std;
//
//
//int Example1() {
//
//    return 0;
//}
//
//int Example2() {
//
//    return 0;
//}
//
//int Example3() {
//
//    return 0;
//}
//
//int Example4() {
//
//    return 0;
//}
//
//
//int Home_task1() {
//
//    return 0;
//}
//
//int Home_task2() {
//
//    return 0;
//}
//
//int Home_task3() {
//
//    return 0;
//}
//
//
//int Menu() {
//
//    while (true) {
//        // Паненко Ян
//        system("cls");
//
//        cout << "ПР_07" << endl;
//        //cout << endl;
//
//        cout << "------------ Меню ------------" << endl;
//        cout << "1. Виконати приклад 1" << endl;
//        cout << "2. Виконати приклад 2" << endl;
//        cout << "3. Виконати приклад 3" << endl;
//        cout << "4. Виконати приклад 4" << endl;
//        cout << endl;
//        cout << "A. Виконати домашнє завдання 1" << endl;
//        cout << "B. Виконати домашнє завдання 2" << endl;
//        cout << "C. Виконати домашнє завдання 3" << endl;
//        cout << endl;
//        cout << "Q. Вийти з програми" << endl;
//        cout << "------------------------------" << endl;
//        cout << endl;
//        cout << "Введіть ваш вибір - ";
//
//        char choice; cin >> choice;
//
//        choice = tolower(choice);
//
//        system("cls");
//
//        switch (choice) {
//        case '1':
//            cout << "Example #1" << "\n\n";
//            Example1();
//            break;
//        case '2':
//            cout << "Example #2" << "\n\n";
//            Example2();
//            break;
//        case '3':
//            cout << "Example #3" << "\n\n";
//            Example3();
//            break;
//        case '4':
//            cout << "Example #4" << "\n\n";
//            Example4();
//            break;
//        case 'a':
//            cout << "Home Work #1" << "\n\n";
//            //Home_task1();
//            break;
//        case 'b':
//            cout << "Home Work #2" << "\n\n";
//            Home_task2();
//            break;
//        case 'c':
//            cout << "Home Work #3" << "\n\n";
//            Home_task3();
//            break;
//        case 'q':
//            cout << "Вихід з програми." << endl;
//            return 0; // Вихід з програми
//        default:
//            cout << "Невірний вибір. Спробуйте ще раз." << endl;
//            break;
//        }
//
//        cout << endl << endl;
//        cout << "Натисніть  клавішу Enter, щоб продовжити...";
//        cin.ignore(); // Ігноруємо залишки вводу
//        cin.get();    // Чекаємо, поки користувач натисне клавішу
//    }
//}
//
//
//
//
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    //Menu();
//
//
//
//    return 0;
//}

#include <iostream>
#include <windows.h>
#include <math.h>


using namespace std;

int Example1() {
    cout << "Виконання прикладу 1\n";
    return 0;
}

int Example2() {
    cout << "Виконання прикладу 2\n";
    return 0;
}

int Example3() {
    cout << "Виконання прикладу 3\n";
    return 0;
}

int Example4() {
    cout << "Виконання прикладу 4\n";
    return 0;
}

int Home_task1() {
    cout << "Виконання домашнього завдання 1\n";
    return 0;
}

int Home_task2() {
    cout << "Виконання домашнього завдання 2\n";
    return 0;
}

int Home_task3() {
    cout << "Виконання домашнього завдання 3\n";
    return 0;
}

// Структура для зберігання пунктів меню
struct MenuItem {
    char choice;
    const char* description;
    const char* shortDesc;
    int (*func)();
};

MenuItem menuItems[] = {
    {'1', "Виконати приклад 1", "Приклад 1", Example1},
    {'2', "Виконати приклад 2", "Приклад 2", Example2},
    {'3', "Виконати приклад 3", "Приклад 3", Example3},
    {'4', "Виконати приклад 4", "Приклад 4", Example4},
    {'A', "Виконати домашнє завдання 1", "Домашнє завдання 1", Home_task1},
    {'B', "Виконати домашнє завдання 2", "Домашнє завдання 2", Home_task2},
    {'C', "Виконати домашнє завдання 3", "Домашнє завдання 3", Home_task3}
};

// Кількість елементів у масиві
const int menuSize = sizeof(menuItems) / sizeof(menuItems[0]);


int Menu() {
    while (true) {
        system("cls");

        cout << "ПР_07\n";                                                                      // Не забудь змінити номер проекту
        cout << "------------ Меню ------------\n";

        for (int i = 0; i < menuSize; i++)
            cout << menuItems[i].choice << ". " << menuItems[i].description << "\n";

        cout << "Q. Вийти з програми\n";
        cout << "------------------------------\n";
        cout << "Введіть ваш вибір - ";

        char choice;
        cin >> choice;
        choice = tolower(choice);
        system("cls");

        if (choice == 'q') {
            cout << "Вихід з програми.\n";
            return 0;
        }

        // Шукаємо вибраний пункт у масиві
        bool found = false;
        for (int i = 0; i < menuSize; i++) {
            if (menuItems[i].choice == choice) {
                cout << menuItems[i].shortDesc << "\n"; // Виводимо лише короткий опис
                menuItems[i].func();  // Викликаємо відповідну функцію
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Невірний вибір. Спробуйте ще раз.\n";

        cout << "\n";
        cout << "Натисніть клавішу Enter, щоб продовжити...";
        cin.ignore();
        cin.get();
    }
}

void test();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Menu();

    test();
    return 0;
}
















void test() {
    
    int f[20], i;

    for (i = 0; i < 20; i++)

        f[i] = i + 1;

    printf(" % d", f + 1);
}