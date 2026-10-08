#include<iostream>
#include<string>
#include<stack>
using namespace std;


string func(string_view s){
    string ans;
    int count{};
    for(char ch : s){
        if(ch == '('){
            if(count>0){
                ans+=ch;
            }
            count++;
        }else{
            count--;
            if(count>0){
                ans+=ch;
            }
            
        }
    }
    return ans;
}
int main() {
    cout<<func("(()()(()))");
    return 0;
}