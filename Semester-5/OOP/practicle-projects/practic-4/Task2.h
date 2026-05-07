//
// Created by yan on 07.05.26.
//

#ifndef PRACTIC_4_TASK2_H
#define PRACTIC_4_TASK2_H


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Task2 {
private:
    // Компаратор для сортування за довжиною (спадання)
    static bool compareDesc(const string& a, const string& b) {
        return a.length() > b.length();
    }

    static void showMass(string arr[], const int lenght) {
        cout << "B = [ ";
        for (int i = 0; i < lenght-1; i++) {
            cout << arr[i] << ", ";
        }
        cout << arr[lenght-1] << "]" << endl;
    }

public:
    static void run() {
        const int lenghtB = 12;
        string B[lenghtB] = {
            "apple", "programming", "C++", "array", "string",
            "function", "lab", "code", "sorting", "variable", "data", "OOP"
        };

        cout << "\n--- Завдання 2: Сортування рядків за довжиною ---" << endl;

        showMass(B, lenghtB);

        sort(B, B + lenghtB, compareDesc);

        showMass(B, lenghtB);
    }
};

#endif //PRACTIC_4_TASK2_H
