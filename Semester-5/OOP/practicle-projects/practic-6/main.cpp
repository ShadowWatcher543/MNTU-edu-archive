#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif


using namespace std;

// Функція очищення консолі
void clearConsole() {
#ifdef _WIN32
    // Windows
    system("cls");
#else
    // Linux/macOS
    system("clear");
#endif
}

class Matrix4x4 {
private:
    int data[4][4];

public:
    // 1. Конструктор без параметрів (0)
    Matrix4x4() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                data[i][j] = 0;
        // Повідомлення конструктора закоментовано для чистоти меню,
        // cout << "[System]: Викликано конструктор за замовчуванням (Matrix 0x0) [ " << this <<  " ]" << endl;
    }

    // 2. Параметризований конструктор
    Matrix4x4(int val) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                data[i][j] = val;
        // Повідомлення конструктора закоментовано для чистоти меню,
        // cout << "[System]: Викликано параметризований конструктор (Matrix filling with " << val << ") [ " << this <<  " ]" << endl;
    }

    // 3. Деструктор
    ~Matrix4x4() {
        // Повідомлення деструктора закоментовано для чистоти меню,
        // cout << "[System]: Об'єкт матриці знищено (Виклик деструктора) [ " << this <<  " ]" << endl;

    }

    // Метод вводу матриці
    void input() {
        cout << "Введіть елементи матриці 4x4:" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << "M[" << i << "][" << j << "] - ";
                cin >> data[i][j];
            }
        }
    }


    // Красивий ввід з [X]
    void inputPro() {
        clearConsole();
        // теперішня кордината вводу і та j
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << "=== Заповнення матриці 4x4 ===" << endl;
                // Кордината відмальовки матриці
                for (int r = 0; r < 4; r++) {
                    for (int c = 0; c < 4; c++) {
                        if (r == i && c == j) cout << setw(6) << "[X]";
                        else if (r < i || (r == i && c < j)) cout << setw(6) << data[r][c];
                        else cout << setw(6) << "?";
                    }
                    cout << endl;
                }
                cout << "\nВведіть M[" << i << "][" << j << "] - ";
                //перевірка типу даних вводу
                while (!(cin >> data[i][j])) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "[!] Введіть ціле число - ";
                }
                clearConsole();
            }
        }
    }

    // Метод виводу матриці
    void display() const {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << setw(5) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Покращений вивід (автоматична ширина)
    void displayPro() const {
        int maxWidth = 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int len = to_string(data[i][j]).length();
                if (len > maxWidth) maxWidth = len;
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << setw(maxWidth + 2) << data[i][j];
            }
            cout << endl;
        }
    }

    // Пошук максимального елемента
    int findMax() const {
        int maxVal = data[0][0];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (data[i][j] > maxVal) maxVal = data[i][j];
            }
        }
        return maxVal;
    }


    // Оператори
    Matrix4x4 operator+(const Matrix4x4& other) {
        Matrix4x4 result;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                result.data[i][j] = this->data[i][j] + other.data[i][j];
        return result;
    }

    Matrix4x4 operator-(const Matrix4x4& other) {
        Matrix4x4 result;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                result.data[i][j] = this->data[i][j] - other.data[i][j];
        return result;
    }
};

void showMenu() {
    Matrix4x4 m1, m2;

    while (true) {
        char choice;
        cout << "\n========== МЕНЮ МАТРИЦЬ ==========\n";
        cout << "1. Створити Матрицю 1 (ввід вручну)\n";
        cout << "2. Створити Матрицю 2 (заповнити числом)\n";
        cout << "3. Вивести обидві матриці та визначити максимальні значення\n";
        cout << "4. Додати матриці (M1 + M2)\n";
        cout << "5. Відняти матриці (M1 - M2)\n";
        cout << "q. Вихід\n";
        cout << "----------------------------------\n";
        cout << "Ваш вибір - ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'q' || choice == 'Q') break;

        switch (choice) {
            case '1':
                m1.inputPro();
                cout << "[OK] Матриця M1 успішно заповнена.\n";
                break;
            case '2':
                int val;
                cout << "Яким числом заповнити Матрицю M2? - ";
                while (!(cin >> val)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "[!] Помилка! Введіть ціле число - ";
                }
                m2 = Matrix4x4(val);
                clearConsole();
                cout << "[OK] Матриця M2 успішно заповнена числом " << val << ".\n";
                break;
            case '3':
                clearConsole();
                cout << "[OK] Вивід матриці M1 та M2:\n";

                cout << "\nМатриця M1:\n";
                m1.displayPro();
                cout << "Максимальний елемент M1: " << m1.findMax() << endl;

                cout << "\nМатриця M2:\n";
                m2.displayPro();
                cout << "Максимальний елемент M2: " << m2.findMax() << endl;
                break;
            case '4': {
                clearConsole();
                cout << "[OK] Результат матриць M1 + M2:\n";
                Matrix4x4 res = m1 + m2;
                res.displayPro();
                break;
            }
            case '5': {
                clearConsole();
                cout << "[OK] Результат матриць M1 - M2:\n";
                Matrix4x4 res = m1 - m2;
                res.displayPro();
                break;
            }
            default:
                clearConsole();
                cout << "[!] Помилка! Введіть символ (1, 2, 3, 4, 5, q) \n";
                break;
        }
    }
}

// void runTask() {
//     cout << "--- Створення першої матриці ---" << endl;
//     Matrix4x4 m1;
//     m1.inputPro();
//     //m1.input();
//
//     int num = 256;
//     cout << "\n--- Створення другої матриці (заповненої '" << num << "' ) ---" << endl;
//     Matrix4x4 m2(num);
//
//     cout << "\nМатриця 1:" << endl;
//     m1.display();
//     cout << "Максимальний елемент M1: " << m1.findMax() << endl;
//
//     cout << "\nМатриця 2:" << endl;
//
//     m2.display();
//     cout << "Максимальний елемент M2: " << m2.findMax() << endl;
//
//     cout << "\nРезультат додавання (M1 + M2):" << endl;
//     Matrix4x4 resAdd = m1 + m2;
//     resAdd.display();
//
//     cout << "\nРезультат віднімання (M1 - M2):" << endl;
//     Matrix4x4 resSub = m1 - m2;
//     resSub.display();
//
//     cout << endl << endl;
// }





int main() {
    // Коректний вивід кирилиці на віндовс
    #ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    #endif

    clearConsole();
    showMenu();
    return 0;
}