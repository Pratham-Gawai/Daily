#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int func1(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto i : nums){
            if( i % k == 0){
                st.insert(i);
            }
        }
        int temp = k;
        while(true){
            if(st.count(temp)) temp+=k;
            else break;
        }
        return temp;
    }

int main() {
    vector<int> temp = { 2,5,4,9,6,8,3,10,12,13,15};
    cout<< func1(temp,8);
    return 0;
}