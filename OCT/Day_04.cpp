#include<iostream>
#include<vector>
#include<string>

using namespace std;
bool isValid1(string& s){
    string demo = s;
    int star = 0;
    // s = "((*)*))"
    int valid = 0;

    for(int i{};i<(int)demo.length();i++){
        char ch = demo[i];
        if(ch == '('){
            valid++;
        }else if(ch =='*'){
            star++;
        }else{
            if(valid>0){
                valid--;
            }else{
                if(star>0){
                    star--;
                }else{
                    return false;
                }
            }
        }
    }
    while(valid>0 && star>0){
        valid--;
        star--;
    }
    cout<<star<<endl;
    cout<<valid<<endl;
    return valid == 0 ? true : false;      
}


int main() {
    string str1 = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";
    cout<<boolalpha;
    cout<<isValid1(str1);
    return 0;
}