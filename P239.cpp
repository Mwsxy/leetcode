#include "header.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for (int i=0; i<k; i++)
        {
            while (!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> ans = {nums[q.front()]};
        for (int i=k; i<nums.size(); i++)
        {
            while (!q.empty() && nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
            if (q.front()<i-k+1)
                q.pop_front();
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};