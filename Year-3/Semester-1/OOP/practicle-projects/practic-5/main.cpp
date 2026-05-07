#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Оголошення структури згідно з варіантом 10
struct Owner {
    string surname;
    string brand;
    string color;
};

class Task1 {
private:
    const static inline string filename = "CAR";

    // Метод для автоматичного створення тестових даних
    static void generateTestData() {
        ofstream outFile(filename, ios::app);
        if (!outFile) return;

        // Тестові набори: {Прізвище, Марка, Колір}
        vector<Owner> testData = {
            {"Іваненко", "Audi", "сірий"},    // Підходить
            {"Петренко", "BMW", "чорний"},
            {"Сидоренко", "Audi", "білий"},
            {"Паненко", "Audi", "сірий"},     // Підходить
            {"Ковальчук", "Toyota", "сірий"},
            {"Бондар", "Audi", "чорний"}
        };

        for (const auto& owner : testData) {
            outFile << owner.surname << "|" << owner.brand << "|" << owner.color << endl;
        }
        outFile.close();
        cout << "[OK] Файл 'CAR' сформовано автоматично з тестовими даними." << endl;
    }

    static void showAudiOwners() {
        // --- Блок читання та фільтрації (згідно з варіантом 10) ---
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "[!] Помилка: Не вдалося відкрити файл для читання." << endl;
            return;
        }

        cout << "\nВласники сірих Audi (пошук у файлі):" << endl;
        cout << "--------------------------------------" << endl;

        string line;
        bool found = false;
        while (getline(inFile, line)) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos) {
                string surname = line.substr(0, pos1);
                string brand = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string color = line.substr(pos2 + 1);

                if (brand == "Audi" && color == "сірий") {
                    cout << ">> " << surname << endl;
                    found = true;
                }
            }
        }

        if (!found) cout << "Таких власників не знайдено." << endl;
        inFile.close();
    }




public:
    static void run() {
        int choice;
        do {
            cout << "\n--- Завдання 1 (ЛР №5): Робота з файлом CAR ---" << endl;
            cout << "1. Ввести дані вручну" << endl;
            cout << "2. Сформувати файл автоматично (тестові дані)" << endl;
            cout << "3. Вивести відомості про власників, які мають автомобілі “Audi” сірого кольору." << endl;
            cout << "4. Очистити данні." << endl;
            cout << "0. Вийти" << endl;


            // Перевірка правильності вводу
            while (!(cout << "Ваш вибір: " && cin >> choice) || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[!] ПОМИЛКА: Вводьте лише цифри (1, 2, 3 або 0)!" << endl;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            switch (choice) {
                case 1 : {
                    // Ввід нових власників
                    int n;
                    while (true) {
                        cout << "Введіть кількість власників: ";
                        if (cin >> n && n > 0) break;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "[!] ПОМИЛКА: Введіть число більше 0." << endl;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    ofstream outFile(filename, ios::app);
                    for (int i = 0; i < n; ++i) {
                        Owner temp;
                        cout << "\nВласник #" << i + 1 << endl;
                        cout << "Прізвище: "; getline(cin, temp.surname);
                        cout << "Марка: ";    getline(cin, temp.brand);
                        cout << "Колір: ";    getline(cin, temp.color);
                        outFile << temp.surname << "|" << temp.brand << "|" << temp.color << endl;
                    }
                    outFile.close();
                    break;
                }
                case 2:
                    generateTestData();
                    break;
                case 3:
                    showAudiOwners();
                    break;
                case 4:{
                    ofstream outFile(filename);
                    outFile.close();
                    cout << "[OK] Файл '"<< filename << "' очищено." << endl;
                    break;
                }
                case 0:
                    cout << "Програма завершена." << endl;
                    break;
                default:
                    cout << "[!] ПОМИЛКА: Невірне значення choice!" << endl;
                    break;
            }
        }while (choice != 0);
    }
};


int main() {
    Task1::run();
    return 0;
}