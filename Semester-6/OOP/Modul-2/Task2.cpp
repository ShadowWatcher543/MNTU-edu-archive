// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
//
// template <typename T>
// class Stack {
//     vector<T> st;
// public:
//     void push(T val) { st.push_back(val); }
//     void pop() { if(!st.empty()) st.pop_back(); }
//
//     string getLongest() {
//         string maxStr = "";
//         for (auto& s : st) {
//             if (s.length() > maxStr.length()) maxStr = s;
//         }
//         return maxStr;
//     }
// };
//
// int main() {
//     Stack<string> st;
//     st.push("cpp");
//     st.push("some long string here");
//     st.push("hello");
//
//     cout << "Найдовший: " << st.getLongest();
// }