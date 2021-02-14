class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,ans=0;
        while (i<nums.size()) {
            if (nums[i]==1) {
                int j = i+1;
                while (j<nums.size() && nums[j]==1) {
                    j++;
                }
                // ans = max(ans, j-i);
                if (j-i>ans) ans = j-i;
                i = j+1;
            }
            else i++;
        }
        return ans;
    }
};