#include<iostream>
#include<vector>

using namespace std;

// the solution takes the TC : O(n^2) and SC : O(n)
vector<int> count(vector<int>&nums,int k){
    int mul = 1;
    vector<int> ans(k,0);
    for(int i{};i<nums.size();i++){
        mul = 1;
        for(int j{i};j<nums.size();j++){
            int rem =  nums[j] % k;
            mul *= rem;
            // mul = mul%k;
            cout<<mul<<endl;
            if(mul==0){
                ans[0]+=(nums.size()-j);
                break;
            } else {
                ans[mul]++;
            }
        }
    }
    return ans;
}
int main() {
    vector<int> temp = {10,2};
    int k = 4;
    auto c = count(temp,k);
    for(auto i : c){
        cout<<i<<" ";
    }
    return 0;
}