// #include <iostream>
// #include <vector>
// using namespace std;
//
// class BaseFact {
// public:
//     virtual ~BaseFact() {}
//     virtual unsigned long long getFact(int n) {
//         unsigned long long res = 1;
//         for (int i = 1; i <= n; i++) res *= i;
//         return res;
//     }
// };
//
// class FactTable : public BaseFact {
//     vector<int> nums;
// public:
//     FactTable(vector<int> n) : nums(n) {}
//
//     void showTable() {
//         cout << "N\tFact\n----------------\n";
//         for (int n : nums) {
//             cout << n << "\t" << getFact(n) << "\n";
//         }
//     }
// };
//
// int main() {
//     vector<int> data = {1, 3, 5, 7, 10};
//     FactTable t(data);
//     t.showTable();
// }