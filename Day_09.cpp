#include <iostream>
#include <string>
#include <vector>
using namespace std;

int func(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0)
        return -1;
    vector<int> min_arr(n);
    int curr_max = INT_MIN;
    min_arr[n - 1] = nums[n - 1];
    for (int i{n - 2}; i >= 0; i--) {
        min_arr[i] = min(min_arr[i + 1], nums[i]);
    }

    for (int i{}; i < n; i++) {
        curr_max = max(curr_max, nums[i]);
        int stability = curr_max - min_arr[i];
        if (stability <= k)
            return i;
    }

    return -1;
}

int main() {
    vector<int> nums = {};
    int k = 1;
    cout << func(nums, k);
    return 0;
}
