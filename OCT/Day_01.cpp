#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.length() % 2)
        return false;
    stack<char> st;
    for (int i = 0; i < (int)s.length(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (!st.empty()) {
                if (ch == ')' && st.top() != '(')
                    return false;
                if (ch == '}' && st.top() != '{')
                    return false;
                if (ch == ']' && st.top() != '[')
                    return false;
                st.pop();
            } else
                return false;
        }
    }
    return st.empty() ? true : false;
}
int main() {
    string demo = "(())()[]{([)}";
	cout<<boolalpha;
	cout<<isValid(demo);
    return 0;
}
