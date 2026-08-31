#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<int> func(ListNode *head) {
    if(!head->next->next) return {-1,-1};
    int f_m{-1},l_m{-1},count{1},min_dis{INT_MAX};
    ListNode* temp = head->next;

    int p_val{head->val},c_val{-1},n_val{-1};

    while(temp->next){
        count++;
        c_val = temp->val;
        n_val = temp->next->val;

        if((p_val>c_val && n_val > c_val) || (p_val<c_val && n_val < c_val)){
            if(f_m == -1){
                f_m = count;
            }else {
                min_dis = min(min_dis,count - l_m);
            }
            l_m = count;
        }
        p_val = temp->val;
        temp=temp->next;
    }

    if(f_m == l_m){
        return {-1,-1};
    }
    return {min_dis,l_m-f_m};
}
int main() {
    ListNode *head = new ListNode();
    int i{},val,size;
    ListNode *temp = head;
    cout<<"Enter the size : ";
    cin>>size;
    while(i<size){
        cout<<"Enter val : ";
        cin>>val;
        temp->next = new ListNode(val);
        temp = temp->next;
        i++;
    }
    auto ans = func(head->next);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}