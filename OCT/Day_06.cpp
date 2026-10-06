#include <iostream>
#include <string>
using namespace std;

int min_number(string_view s) {
    int ans{};
    int curr{};
    for (char ch : s) {
        if (ch == '(')
            curr++;
        else {
            curr--;
            if (curr < 0) {
                ans++;
                curr = 0;
            }
        }
    }
    return ans + abs(curr);
}
int main() {
    cout <<min_number("(((()(()()");
    return 0;
}