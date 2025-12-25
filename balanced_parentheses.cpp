// balanced_parentheses.cpp
// Compile: g++ -std=c++17 balanced_parentheses.cpp -o balanced_parentheses
// Usage: ./balanced_parentheses
// Enter the string when prompted (e.g. "([]){}" or "( [ ) )")

#include <bits/stdc++.h>
using namespace std;

bool isOpening(char c) {
    return c == '(' || c == '[' || c == '{';
}
bool isClosing(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(const string &s) {
    vector<char> st;
    for (char c : s) {
        if (isOpening(c)) {
            st.push_back(c);
        } else if (isClosing(c)) {
            if (st.empty()) return false;
            char top = st.back();
            st.pop_back();
            if (!matches(top, c)) return false;
        } else {
            // ignore other characters (optional). If you want to treat others as error, return false.
            continue;
        }
    }
    return st.empty();
}

int main() {
    cout << "Enter string to check for balanced parentheses:\n";
    string line;
    getline(cin, line);

    if (isBalanced(line)) {
        cout << "Balanced\n";
    } else {
        cout << "Not balanced\n";
    }
    return 0;
}
