#include "header.h"
#include <algorithm>
#include <queue>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1);
        if (nums.empty()) return ret;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
        q.emplace(nums[0],0);
        for (int i=1; i<nums.size();i++){
            while (!q.empty() && nums[i] > q.top().first) {
                ret[q.top().second] = nums[i];
                q.pop();
            }
            q.emplace(nums[i], i);
        }
        for (int i=0; i<nums.size(); i++) {
            while (!q.empty() && nums[i] > q.top().first) {
                ret[q.top().second] = nums[i];
                q.pop();
            }
        }
        return ret;
    }
};

int main() {
    vector<int> a;
    a = {2,2,3,3,4,5,6,7,1};
    // a = {5,4,3,2,1};
    print(Solution().nextGreaterElements(a));
    return 0;
}