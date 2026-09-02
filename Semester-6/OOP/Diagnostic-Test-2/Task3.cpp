// #include <iostream>
// #include <cmath>
// using namespace std;
//
// class Equation {
// public:
//     virtual ~Equation() {}
//     virtual void solve() = 0;
// };
//
// class Linear : public Equation {
//     double a, b;
// public:
//     Linear(double a, double b) : a(a), b(b) {}
//     void solve() override {
//         if (a == 0) cout << "Немає розв'язків\n";
//         else cout << "x = " << (-b / a) << "\n";
//     }
// };
//
// class Quad : public Equation {
//     double a, b, c;
// public:
//     Quad(double a, double b, double c) : a(a), b(b), c(c) {}
//     void solve() override {
//         double d = b * b - 4 * a * c;
//         if (d < 0) cout << "Немає коренів\n";
//         else if (d == 0) cout << "x = " << (-b / (2 * a)) << "\n";
//         else cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << ", x2 = " << (-b - sqrt(d)) / (2 * a) << "\n";
//     }
// };
//
// int main() {
//     Equation* eq[2];
//     eq[0] = new Linear(2, -4);
//     eq[1] = new Quad(1, -5, 6);
//
//     for (int i = 0; i < 2; i++) {
//         eq[i]->solve(); // пізнє зв'язування
//         delete eq[i];
//     }
// }