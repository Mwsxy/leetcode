#include "header.h"
#include <vector>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        int i =0;
        while (i<n) {
            int k = nums[i]-1;
            swap(nums[k], nums[i]);
            if (nums[i]==i+1 || nums[k]==nums[i]) i++;
        }
        // print(nums);
        for (int i=0; i<n; i++) {
            int k = nums[i];
            if (i+1!=k) ret.push_back(i+1);
        }
        return ret;
    }
};

int main() {
    vector<int> nums;
    nums = {2,3,4,5,6,7,8,1};
    auto ret = Solution().findDisappearedNumbers(nums);
    print(ret);
    return 0;
}