#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


string output(string& s ,vector<vector<string>>& know){
    unordered_map<string,string> mp;

    for(auto i : know){
        mp[i[0]] = i[1];
    }
    string ans = "";
    string key = "";
    bool addtokey = false;
    for(auto i : s){
        if(i=='('){
            addtokey = true;
            continue;
        }else if(i==')'){
            addtokey = false;
            ans += mp[key];
            key = "";
            continue;
        }
        if(addtokey){
            key+=i;
            continue;
        }
        ans += i;
    }
    return ans;
}
int main() {
    string s = "(name)is(age)yearsold";
    vector<vector<string>> nums = { {"name","bob"},{"age","two"}};
    cout<<'\n';
    cout<<output(s,nums);
    return 0;
}