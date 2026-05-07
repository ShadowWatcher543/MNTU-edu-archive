//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class University {
//protected:
//    string name;
//public:
//    University(const string& n) : name(n) {}
//    virtual void print() const {
//        cout << "University: " << name << endl;
//    }
//    virtual ~University() {}
//};
//
//class Faculty : public University {
//    string facultyName;
//public:
//    //конструктор
//    Faculty(const string& uName, const string& fName)
//        : University(uName), facultyName(fName) {
//    }
//    
//    //гетер
//    string getFacultyName() const { return facultyName; }
//
//    //прінт
//    void print() const override {
//        cout << "Faculty: " << facultyName << ", University: " << name << endl;
//    }
//};
//
//class Department : public Faculty {
//    string deptName;
//public:
//    //конструктор
//    Department(const string& uName, const string& fName, const string& dName)
//        : Faculty(uName, fName), deptName(dName) {
//    }
//    //прінт
//    void print() const override {
//        cout << "Department: " << deptName << ", Faculty: " << getFacultyName() << ", University: " << name << endl;
//    }
//};
//
//int main() {
//    University university = University ("Kyiv University");
//    Faculty faculty = Faculty("Kyiv University", "Faculty of Physics");
//    Department department = Department("Kyiv University", "Faculty of Physics", "Department of Quantum Mechanics");
//
//    University* arr[] = { &university, &faculty, &department };
//
//    for (auto ptr : arr) {
//        ptr->print();
//    }
//
//    return 0;
//}





//#include <iostream>
//#include <cmath>
//
//const double PI = 3.14159265358979323846;
//
//class Solid {
//public:
//    virtual void print() const = 0;
//    virtual double volume() const = 0;
//    virtual ~Solid() {}
//};
//
//class Cone : public Solid {
//    double radius;
//    double height;
//public:
//    //Конструктор
//    Cone(double r, double h) : radius(r), height(h) {}
//    void print() const override {
//        cout << "Cone with radius = " << radius << " and height = " << height
//            << ", volume = " << volume() << endl;
//    }
//    //Розрахунок об'єму
//    double volume() const override {
//        return PI * pow(radius, 2) * height / 3.0;
//    }
//};
//
//int main() {
//    Cone c1(3, 5);
//    Cone c2(2, 4);
//
//    Solid* solids[] = { &c1, &c2 };
//
//    for (auto s : solids) {
//        s->print();
//    }
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//template <typename T>
//void findInRange(const vector<T>& arr, T min, T max) {
//    for (const auto& elem : arr) {
//        if (elem >= min && elem <= max) {
//            cout << elem << " ";
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    vector<int> v = { 1, 5, 8, 10, 15 };
//    vector<double> d = { 0.5, 2.3, 4.5, 5.1 };
//
//    cout << "Integers in range 5-10: ";
//    findInRange(v, 5, 10);
//
//    cout << "Doubles in range 1.0-5.0: ";
//    findInRange(d, 1.0, 5.0);
//
//    return 0;
//}




//#include <iostream>
//
//using namespace std;
//
//template <typename T1, typename T2>
//class Pair {
//    T1 first;
//    T2 second;
//public:
//    //Конструктор
//    Pair(T1 a, T2 b) : first(a), second(b) {}
//
//    //Вивід
//    void print() const {
//        cout << "Pair: (" << first << ", " << second << ")" << endl;
//    }
//};
//
//int main() {
//    Pair<int, double> p1(5, 3.14);
//    Pair<string, int> p2("Age", 25);
//
//    p1.print();
//    p2.print();
//
//    return 0;
//}