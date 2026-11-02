#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

int func(vector<int>&nums){
    int n = nums.size();

    nth_element(begin(nums), begin(nums) + n / 2, end(nums));
    int mid = nums[n / 2];

    int cnt{};
    for(int i =0;i<n/2;i++){
        cnt += abs(nums[i]-mid);
        cnt += abs(nums[n-i-1]-mid);
    }
    return cnt;
}
int main() {
    vector<int> nums = {1,30,4};
    cout<<func(nums);
    return 0;
}