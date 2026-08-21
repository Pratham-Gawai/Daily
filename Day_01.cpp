#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>           
using namespace std;

// TC : O(n) and SC : O(n)
vector<int> Combine(vector<int> &nums) {
    vector<int> left;
    vector<int> right;
    if (left.empty() && right.empty()) {
        left.push_back(nums[0]);
        right.push_back(nums[1]);
    }
    for (size_t i = 2; i < nums.size(); i++) {
        left.back() > right.back() ? left.push_back(nums[i]) : right.push_back(nums[i]);
    }
    nums.clear();
    for (auto i : left)
        nums.push_back(i);
    for (auto i : right)
        nums.push_back(i);
    return nums;
}

int main() {
    vector<int> temp = {1,5,4,8,6,7,9,3,1,5,15,10,8};
    auto ans = Combine(temp);
    cout<<"Elements are : ";
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
    return 0; 
}