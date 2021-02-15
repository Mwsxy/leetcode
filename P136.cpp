#include "header.h"
#include <vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t=0;
        for (int i:nums)
            t^=i;
        t^=0;
        return t;
    }
};

int main() {
    vector<int> nums;
    nums = {4,1,2,1,2};
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}