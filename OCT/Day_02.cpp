#include<iostream>
#include<vector>
#include<string>
using namespace std;
void add(string st, char ch, int valid,size_t size,vector<string>& ans,int n){
    if(valid<0) return;
    st+=ch;
    if(st.length()==size){
        ans.push_back(st);
        return;
    }
    if(n>0) add(st,'(',valid+1,size,ans,n-1);
    add(st,')',valid-1,size,ans,n);

}
vector<string> func(int n){
    vector<string>ans;
    if(n == 0) return ans;
    size_t size = n*2;
    add("",'(',1,size,ans,n-1);
    return ans;
}
int main() {
    auto ans = func(4);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}