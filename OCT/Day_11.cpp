#include <iostream>
#include <vector>
using namespace std;

int sumOfSquares(vector<int> &nums) {
    int sum = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (!((int)nums.size() % (i + 1))) {
            sum += (nums[i] * nums[i]);
        }
    }
    return sum;
}
int main() {
    vector<int> nums = {1,2,3,4};
    cout<<sumOfSquares(nums);
    return 0;
}