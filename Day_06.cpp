#include<iostream>
#include<vector>
#include<string>
#include<ranges>
#include<algorithm>
using namespace std;

int func(vector<int>& nums){
    int min_idx = ranges::min_element(nums)-nums.begin();
    int max_idx = ranges::max_element(nums)-nums.begin();

    int first = min(min_idx,max_idx);
    int last = max(min_idx,max_idx);

    int ans1 = last + 1;

    int ans2 = nums.size() - first ;

    int ans3 = first + 1 + nums.size() - last ;

    return min({ans1,ans2,ans3});
}

int main() {
    vector<int> nums {2,10,7,5,4,1,8,6};
    cout<<nums.size()<<endl;
    cout<<func(nums);
    return 0;
}