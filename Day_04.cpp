#include <iostream>
#include <string>
#include <vector>
using namespace std;

// My Approach first time 
string func(string s, int k) {
    int l{}, r{}, window_size{INT_MAX}, start_l{-1}, req_ones{k};
    int n = s.length();
    while (r < n) {
        if (s[r] == '1')
            req_ones--;

        while (s[l] == '0') {
            l++;
            if (l == n)
                return "";
        }

        int curr_window_size = r - l + 1;
        if (req_ones == 0) {
            if (curr_window_size < window_size ||
                (curr_window_size == window_size &&
                 (s.substr(l, curr_window_size) <
                  s.substr(start_l, window_size)))) {
                window_size = curr_window_size;
                start_l = l;
                if (window_size == k)
                    return s.substr(start_l, window_size);
            }
            l++;
            req_ones++;
        }
        r++;
    }
    return window_size == INT_MAX ? "" : s.substr(start_l, window_size);
}

// by using some help of chatgpt
string shortestBeautifulSubstring(string s, int k) {
    int l{}, r{}, window_size{INT_MAX}, start_l{-1}, req_ones{k};
    int n = s.length();
    while (r < n) {
        if (s[r] == '1')
            req_ones--;

        while (s[l] == '0')
            l++;

        int curr_window_size = r - l + 1;

        if (req_ones == 0) {

            if ((curr_window_size < window_size) ||
                (curr_window_size == window_size &&
                 (s.substr(l, curr_window_size) <
                  s.substr(start_l, window_size)))) {
                window_size = curr_window_size;
                start_l = l;
            }

            if (s[l] == '1') {
                l++;
                req_ones++;
            }
        }
        r++;
    }
    return window_size == INT_MAX ? "" : s.substr(start_l, window_size);
}

int main() {
    cout << func("1100001110111100100", 8);
    return 0;
}