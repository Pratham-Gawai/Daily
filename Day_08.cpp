#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool uniformArray(vector<int> &nums1) {
    int minOdd = INT_MAX;
    int minEven = INT_MAX;

    for (auto i : nums1) {
        if (i % 2 == 0) {
            minEven = min(minEven, i);
        } else {
            minOdd = min(minOdd, i);
        }
    }
    if (minOdd == INT_MAX) {
        return true;
    }

    return minEven > minOdd;
}
int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    cout<<uniformArray(nums);
    return 0;
}