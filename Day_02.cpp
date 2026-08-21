#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


// MY Approach (TLE is present for small k ans is correct)
// TC : O(m + k log(m) ) m = length of nums
long long func(vector<int> &nums, int k) {
    vector<int> UniqeCoin;

    for (int x : nums) {
        bool isMultiple = false;
        for (int y : nums) {
            if (x != y && x % y == 0) {
                isMultiple = true;
                break;
            }
        }
        if (!isMultiple)
            UniqeCoin.push_back(x);
    }

    long long ans = 0;
    int num = k;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;

    for (int i : UniqeCoin) {
        pq.push({i, i});
    }

    while (num > 0) {
        // many elements having same val
        if (pq.top().first == ans) {
            auto ele = pq.top();
            ele.first += ele.second;
            pq.pop();
            pq.push(ele);
            continue;
        }

        auto ele = pq.top();
        ans = ele.first;
        ele.first += ele.second;
        
        pq.pop();
        pq.push(ele);
        num--;
    }
    return ans;
}

int main() {
    vector<int> nums = {5,6};
    cout<<func(nums, 15);
    return 0;
}