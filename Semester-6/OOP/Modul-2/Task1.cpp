// #include <iostream>
// #include <vector>
// using namespace std;
//
// class Shape {
// protected:
//     double x, y;
//     double angle;
//     double scale;
// public:
//     Shape(double x = 0, double y = 0, double angle = 0, double scale = 1.0)
//         : x(x), y(y), angle(angle), scale(scale) {}
//
//     virtual ~Shape() {}
//
//     virtual void draw() = 0;
//     virtual void hide() = 0;
//
//     virtual void rotate(double deg) {
//         angle += deg;
//         cout << "Повернуто на " << deg << " град. Поточний кут: " << angle << endl;
//     }
//
//     virtual void move(double dx, double dy) {
//         x += dx;
//         y += dy;
//         cout << "Переміщено на (" << dx << ", " << dy << "). Нова позиція: (" << x << ", " << y << ")" << endl;
//     }
// };
//
// class Triangle : public Shape {
// public:
//     Triangle(double x, double y) : Shape(x, y) {}
//     void draw() override { cout << "Малюємо трикутник в (" << x << ", " << y << ")\n"; }
//     void hide() override { cout << "Ховаємо трикутник\n"; }
// };
//
// class Quad : public Shape {
// public:
//     Quad(double x, double y) : Shape(x, y) {}
//     void draw() override { cout << "Малюємо чотирикутник в (" << x << ", " << y << ")\n"; }
//     void hide() override { cout << "Ховаємо чотирикутник\n"; }
// };
//
// class Polygon : public Shape {
// public:
//     Polygon(double x, double y) : Shape(x, y) {}
//     void draw() override { cout << "Малюємо багатокутник в (" << x << ", " << y << ")\n"; }
//     void hide() override { cout << "Ховаємо багатокутник\n"; }
// };
//
// int main() {
//     Shape* shapes[3];
//     shapes[0] = new Triangle(1, 2);
//     shapes[1] = new Quad(3, 4);
//     shapes[2] = new Polygon(5, 6);
//
//     for (int i = 0; i < 3; i++) {
//         shapes[i]->draw();
//         shapes[i]->rotate(45);
//         shapes[i]->move(2, 3);
//         shapes[i]->hide();
//         cout << "-------------------\n";
//     }
//
//     for (int i = 0; i < 3; i++) {
//         delete shapes[i];
//     }
//
//     return 0;
// }