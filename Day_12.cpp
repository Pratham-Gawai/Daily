#include <iostream>
#include <algorithm>
#include <vector>
#include<numeric>
#include<unordered_map>
#include<numeric>

using namespace std;
// this code TC : O(n) and SC : O(n)
int min_count(vector<int> &nums, int x) {
    int temp = x;
    int sum = 0;
    unordered_map<int, int> s1;
    unordered_map<int, int> s2;
    int count1 = 0;
    for (size_t i{}; i < nums.size(); i++) {
        sum += nums[i];
        count1++;
        if (sum > temp) {
            count1 = INT_MAX;
            break;
        }
        if (sum == x)
            break;
        s1.insert({sum, count1});
    }
    if (sum < x)
        count1 = INT_MAX;
    sum = 0;
    int count2 = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        sum += nums[i];
        count2++;
        if (sum > temp) {
            count2 = INT_MAX;
            break;
        }
        if (sum == x)
            break;
        s2.insert({sum, count2});
    }
    if (sum < x)
        count2 = INT_MAX;
    int count3 = INT_MAX;
    for (auto i : s1) {
        int diff = temp - i.first;
        if (s2.find(diff) != s2.end()) {
            auto it = s2.find(diff);
            if (i.second + it->second < (int)nums.size()) {
                count3 = min(count3, it->second + i.second);
            }
        }
    }
    int mini = min({count1, count2, count3});
    return (mini == INT_MAX || mini == 0) ? -1 : mini;
}


// MY Second Approach TC : O(n) and SC :O(n)
int minOperations(vector<int> &nums, int x) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if(total == x) return nums.size();
    if(total-x<0) return -1;


    int sum = 0;
    int sp = 0;
    int count2{};
    int n = nums.size();
    for(int curr = 0;curr<2*n && sp<n ;curr++){
        sum += nums[curr % n];
        
        while(sum>x && sp<curr){
            sum -= nums[sp % n];
            sp++;
        }

        if(sum == x){
            if(curr >= n){
                count2 = min(count2,curr - sp + 1);
            }
        }
    }
    return (count2==INT_MAX) ? -1 : count2;
}

int main() {
    vector<int> nums = {6, 6, 6, 6, 6, 6, 6, 5};
    int x = 12;
    cout << boolalpha;
    cout << minOperations(nums, x);
    return 0;
}