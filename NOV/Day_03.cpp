#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(vector<int>&nums){
    int m = *max_element(begin(nums),end(nums));
    int cnt{};
    for(auto i : nums){
        cnt+= abs(m-i);
    }
    return cnt;
}
int main() {
    vector<int> nums = {2,1,3};
    cout<<func(nums);
    return 0;
}