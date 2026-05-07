#include <iostream>

using namespace std;

class coord {
    int x, y;

public:
    coord() {
        x = 0;
        y = 0;
    }
    coord(int i, int j) {
        x = i;
        y = j;
    }

    void get_xy(int &i, int &j) {
        i = x;
        j = y;
    }

    // Оголошення дружньої функції
    friend coord operator+(int i, coord ob);
};

// Визначення оператора-функції для int + coord
coord operator+(int i, coord ob) {
    coord temp;
    temp.x = i + ob.x;
    temp.y = i + ob.y;
    return temp;
}

int main() {
    coord o1(10, 10), o2;
    int x, y;

    // Виклик оператора-функції: число + об'єкт
    o2 = 5 + o1;

    o2.get_xy(x, y);
    cout << "Результат (5 + 10, 5 + 10): " << x << ", " << y << endl;

    return 0;
}