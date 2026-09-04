#include <iostream>
#include <cstdarg>
using namespace std;

// a) Перевантаження функцій (посилання)
void sumOverload(int& res, int a, int b) {
    res = a + b;
}

void sumOverload(int& res, int a, int b, int c) {
    res = a + b + c;
}

// a) Перевантаження функцій (вказівник)
void sumOverload(int* res, int a, int b) {
    if (res) *res = a + b;
}

// б) Параметри за замовчуванням (посилання та вказівник)
void sumDefault(int& res, int a, int b, int c = 0, int d = 0) {
    res = a + b + c + d;
}

void sumDefault(int* res, int a, int b, int c = 0, int d = 0) {
    if (res) *res = a + b + c + d;
}

// в) Змінна кількість параметрів (f(int&, ...))
// Перший параметр під залежність: count вказує скільки аргументів іде далі
void sumVarargs(int& res, int count, ...) {
    va_list args;
    va_start(args, count);
    res = 0;
    for (int i = 0; i < count; i++) {
        res += va_arg(args, int);
    }
    va_end(args);
}

// через вказівник
void sumVarargs(int* res, int count, ...) {
    if (!res) return;
    va_list args;
    va_start(args, count);
    *res = 0;
    for (int i = 0; i < count; i++) {
        *res += va_arg(args, int);
    }
    va_end(args);
}

int main() {
    int r1 = 0;

    // Перевантаження
    sumOverload(r1, 5, 10);
    cout << "Overload ref: " << r1 << endl;

    sumOverload(&r1, 1, 2);
    cout << "Overload ptr: " << r1 << endl;

    // Default params
    sumDefault(r1, 10, 20, 30);
    cout << "Default ref: " << r1 << endl;

    // Varargs (...)
    sumVarargs(r1, 4, 1, 2, 3, 4); // сума 4-х чисел
    cout << "Varargs ref: " << r1 << endl;

    sumVarargs(&r1, 3, 10, 20, 30); // сума 3-х чисел
    cout << "Varargs ptr: " << r1 << endl;

    return 0;
}