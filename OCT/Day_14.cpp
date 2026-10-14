#include<iostream>
#include<vector>
#include<string>

using namespace std;

// num = 1, sum = 10
string func(int sum , int num){
    string ans ="";
    if(sum>num*9){
        return "";  
    }
    while(num>0){
        int dig = (sum>=9) ? 9 : 0;
        ans+=to_string(dig);
        sum-=dig;
        num--;
    }
    return ans;
}
int main() {
    cout << func(39,4);
    return 0;
}