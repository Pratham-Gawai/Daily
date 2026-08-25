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
    return 0;
}