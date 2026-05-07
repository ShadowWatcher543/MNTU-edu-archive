#ifndef PRACTIC_4_TASK1_H
#define PRACTIC_4_TASK1_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct Student {
    int id;
    string name;
    int m1, m2, m3, m4;
};

class Task1 {
private:
    // Допоміжна функція для підрахунку візуальних символів UTF-8
    static int getVisualLength(const string& s) {
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] & 0xc0) != 0x80) length++;
        }
        return length;
    }

public:
    static void run() {
        vector<Student> group = {
            {1, "Іванчук С.О.", 4, 3, 3, 4},
            {2, "Панченко І.А.", 5, 4, 4, 5},
            {3, "Заєць О.М.", 3, 4, 4, 4},
            {4, "Вельбицький П.О.", 4, 3, 3, 3},
            {5, "Сидоренко В.Р.", 2, 3, 3, 2},
            {6, "Кравченко З.І.", 3, 5, 4, 5},
            {7, "Якубів Р.Н.", 5, 4, 4, 3},
            {8, "Зоренко П.М.", 4, 2, 3, 3},
            {9, "Берестяк Г.С.", 4, 5, 5, 5},
            {10, "Дячик Н.С.", 5, 5, 4, 4}
        };

        // 1. Знаходимо максимальну довжину імені серед тих, хто підходить під критерій
        int maxNameWidth = 15; // Мінімальна ширина для заголовка "Прізвище"
        for (const auto& s : group) {
            if (s.m1 >= 4 && s.m2 >= 4 && s.m3 >= 4 && s.m4 >= 4) {
                maxNameWidth = max(maxNameWidth, getVisualLength(s.name));
            }
        }

        // 2. Будуємо динамічну горизонтальну лінію
        // 4 (ID) + maxNameWidth + 4 стовпчики по 6 символів
        string nameLine(maxNameWidth, '-');
        string line = "+----+-" + nameLine + "-+-----+-----+-----+-----+";

        cout << "\n>>> ТАБЛИЦЯ СТУДЕНТІВ <<<" << endl;
        cout << line << endl;

        // Шапка
        cout << "| ID | " << "Прізвище";
        for(int i = 0; i < maxNameWidth - 8; i++) cout << " "; // 8 - довжина слова Прізвище
        cout << " | ІНФ | МАТ | ФІЗ | ПРГ |" << endl;

        cout << line << endl;

        // 3. Вивід даних
        for (const auto& s : group) {
            if (s.m1 >= 4 && s.m2 >= 4 && s.m3 >= 4 && s.m4 >= 4) {
                // ID
                cout << "| " << (s.id < 10 ? " " : "") << s.id << " | ";

                // Ім'я + адаптивні пробіли
                cout << s.name;
                int currentLen = getVisualLength(s.name);
                for (int sp = 0; sp < (maxNameWidth - currentLen) + 1; sp++) cout << " ";

                // Оцінки
                printf("|  %d  |  %d  |  %d  |  %d  |\n", s.m1, s.m2, s.m3, s.m4);
            }
        }
        cout << line << endl;
    }
};

#endif