#include "header.h"
#include <queue>

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        priority_queue<int> q;
        for (int i:nums) q.push(i);
        int ans = 0;
        while (!q.empty()) {
            int a,b;
            a = q.top(); q.pop();
            b = q.top(); q.pop();
            ans += min(a,b);
        }
        return ans;
    }
};

int main() {
    return 0;
}