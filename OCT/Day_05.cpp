#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int number(string_view s) {
    int ans = 0, count = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            count++;
        } else {
            count--;
            if (s[i - 1] == '(') {
                ans += 1 << count;
            }
        }
    }
    return ans;
}
int main() {
    cout << number("(()(()))");
    return 0;
}