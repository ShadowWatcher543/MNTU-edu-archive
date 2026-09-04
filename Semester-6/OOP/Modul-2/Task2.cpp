// #include <iostream>
// using namespace std;
//
// class Counter {
// private:
//     int minVal;
//     int maxVal;
//     int current;
//
// public:
//     Counter(int minV = 0, int maxV = 10) : minVal(minV), maxVal(maxV), current(minV) {
//         if (minVal >= maxVal) {
//             minVal = 0;
//             maxVal = 10;
//             current = 0;
//         }
//     }
//
//     void setRange(int minV, int maxV) {
//         if (minV < maxV) {
//             minVal = minV;
//             maxVal = maxV;
//             if (current < minVal || current > maxVal) {
//                 current = minVal;
//             }
//         }
//     }
//
//     void increment() {
//         current++;
//         if (current >= maxVal) {
//             current = minVal;
//         }
//     }
//
//     int getValue() const {
//         return current;
//     }
// };
//
// int main() {
//     Counter c(0, 3);
//
//     for (int i = 0; i < 5; i++) {
//         cout << "Значення: " << c.getValue() << endl;
//         c.increment();
//     }
//
//     return 0;
// }