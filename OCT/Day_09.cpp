#include<iostream>
#include<string>
using namespace std;

int func(string_view s){
    int ans{};
    int count{};

    for(char ch : s){
        if(ch == '('){
            if(count<0){
                if(abs(count)%2 == 0){
                    ans+=abs(count)/2;
                }else{
                    count++;
                    cout<<count<<endl;
                    ans+=abs(count)/2;
                    cout<<ans<<endl;
                    ans+=2;
                }
                count = 0;
            }
            count+=2;
        }else{
            count--;
        }
    }
    return ans;
}
int main() {
    cout<<func(")())");
    return 0;
}