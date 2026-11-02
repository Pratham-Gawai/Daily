#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int func(vector<int>&nums){
    int m = *min_element(begin(nums),end(nums));
    int cnt{};
    for(auto i : nums){
        cnt+= abs(i-m);
    }
    return cnt;
}
int main() {
    vector<int> nums = {1,2,3,4,5,6};
    cout<<func(nums);
    return 0;
}