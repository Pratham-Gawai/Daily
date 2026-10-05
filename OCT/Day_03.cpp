#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;
int max_lenght(string s){
    int max_len = 0 ;
    int len = 0;
    stack<char> st;

    for(int i = 0 ;i<s.length();i++){
        char ch = s[i];
        if(ch == ')'){
            if(st.empty()){
                max_len = max(max_len,len);
                len = 0;
                while(!st.empty()){
                    st.pop();
                }
                continue;
            } else {
                if(st.top()=='('){
                    len = len + 2;
                    st.pop();
                }
            }
        }else {
            st.push(ch);
        }
    }
    if(st.empty()) max_len = max(len,max_len);
    return max_len;
}
int main() {
    cout<<max_lenght("()(()");
    return 0;
}