// #include <iostream>
// using namespace std;
//
// template <typename T>
// class Matrix {
// private:
//     int rows, cols;
//     T** data;
//
//     void allocate() {
//         data = new T*[rows];
//         for (int i = 0; i < rows; i++) {
//             data[i] = new T[cols]();
//         }
//     }
//
//     void free() {
//         if (data) {
//             for (int i = 0; i < rows; i++) {
//                 delete[] data[i];
//             }
//             delete[] data;
//         }
//     }
//
// public:
//     Matrix(int r, int c) : rows(r), cols(c) {
//         allocate();
//     }
//
//     ~Matrix() {
//         free();
//     }
//
//     int getRows() const { return rows; }
//     int getCols() const { return cols; }
//
//     T* operator[](int index) { return data[index]; }
//     const T* operator[](int index) const { return data[index]; }
//
//     // копіювання всього масиву за рядками
//     Matrix<T> copyByRows() const {
//         Matrix<T> res(rows, cols);
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 res.data[i][j] = data[i][j];
//             }
//         }
//         return res;
//     }
//
//     // копіювання за стовпцями
//     Matrix<T> copyByCols() const {
//         Matrix<T> res(rows, cols);
//         for (int j = 0; j < cols; j++) {
//             for (int i = 0; i < rows; i++) {
//                 res.data[i][j] = data[i][j];
//             }
//         }
//         return res;
//     }
//
//     // копіювання одного рядка
//     T* copyRow(int r) const {
//         T* rowCopy = new T[cols];
//         for (int j = 0; j < cols; j++) {
//             rowCopy[j] = data[r][j];
//         }
//         return rowCopy;
//     }
//
//     // копіювання одного стовпчика
//     T* copyCol(int c) const {
//         T* colCopy = new T[rows];
//         for (int i = 0; i < rows; i++) {
//             colCopy[i] = data[i][c];
//         }
//         return colCopy;
//     }
//
//     // копіювання головної діагоналі
//     T* copyMainDiagonal(int& size) const {
//         size = (rows < cols) ? rows : cols;
//         T* diag = new T[size];
//         for (int i = 0; i < size; i++) {
//             diag[i] = data[i][i];
//         }
//         return diag;
//     }
//
//     template <typename U>
//     friend ostream& operator<<(ostream& os, const Matrix<U>& m);
//
//     template <typename U>
//     friend istream& operator>>(istream& is, Matrix<U>& m);
// };
//
// template <typename T>
// ostream& operator<<(ostream& os, const Matrix<T>& m) {
//     for (int i = 0; i < m.rows; i++) {
//         for (int j = 0; j < m.cols; j++) {
//             os << m.data[i][j] << " ";
//         }
//         os << "\n";
//     }
//     return os;
// }
//
// template <typename T>
// istream& operator>>(istream& is, Matrix<T>& m) {
//     for (int i = 0; i < m.rows; i++) {
//         for (int j = 0; j < m.cols; j++) {
//             is >> m.data[i][j];
//         }
//     }
//     return is;
// }
//
// int main() {
//     Matrix<int> m(2, 2);
//     cout << "Введіть 4 числа для матриці 2x2:\n";
//     cin >> m;
//
//     cout << "Матриця:\n" << m;
//
//     int diagSize = 0;
//     int* diag = m.copyMainDiagonal(diagSize);
//     cout << "Діагональ: ";
//     for (int i = 0; i < diagSize; i++) cout << diag[i] << " ";
//     cout << endl;
//
//     delete[] diag;
//     return 0;
// }