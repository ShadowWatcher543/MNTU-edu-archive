#include <iostream>
#include <limits>
#include "Task1.h"
#include "Task2.h"

using namespace std;

int main() {

    int choice;
    do {
        cout << "\n========== МЕНЮ ЛАБОРАТОРНОЇ РОБОТИ ==========" << endl;
        cout << "1. Запустити Завдання 1 (Студенти)" << endl;
        cout << "2. Запустити Завдання 2 (Сортування масиву)" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";

        cin >> choice;

        // Перевірка на помилку вводу
        if (cin.fail()) {
            cin.clear(); // Скидаємо прапор помилки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищуємо буфер
            cout << "\n[!] ПОМИЛКА: Вводьте лише цифри (1, 2, 0)!" << endl;
            choice = 7;
            continue;
        }

        switch (choice) {
            case 1:
                Task1::run();
                break;
            case 2:
                Task2::run();
                break;
            case 0:
                cout << "Програма завершена." << endl;
                break;
            default:
                cout << "\n[!] ПОМИЛКА: Вводьте лише цифри (1, 2, 0)!" << endl;
        }
    } while (choice != 0);

    return 0;
}