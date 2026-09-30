#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int> solve(string& nums){
    vector<int> ans(nums.length(),0);
    int d = 0;
    for(int i{};i<nums.length();i++){
        if(nums[i]=='('){
            d++;
            ans[i] = d %2;
        }else{
            d--;
            ans[i] = d%2;
        }
    }
    return ans;
}
int main() {
    string nums = "()(()())";
    auto ans = solve(nums);

    for(int i : ans){
        cout<<i<<" ";
    }
    
    return 0;
}