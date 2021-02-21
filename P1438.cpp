#include "header.h"
#include <queue>
#include <vector>

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.empty()) return 0;
        int h,t;
        int _M, _m, Mi, mi;
        h = 0;
        t = 1;
        _M = _m = nums.front();
        Mi=mi=h;
        int ans = 1;
        while (t<nums.size()) {
            if (abs(nums[t]-nums[t-1])>limit) {
                h=t;
                t=h+1;
                _M = _m = nums[h];
                Mi = mi = h;
            }
            else if (nums[t]<=_M && nums[t]>=_m) {
                t++;
            }
            else if (nums[t]>_M) {
                if (nums[t]-_m <=limit) {
                    _M = nums[t];
                    Mi = t;
                    t++;
                }
                else {
                    h = mi+1;
                    _m = nums[h];
                    mi = h;
                    for (int i=h; i<t; i++) {
                        if (nums[i]<=_m) {
                            _m = nums[i];
                            mi = i;
                        }
                    }
                }
            }
            else if (nums[t]<_m) {
                if (_M-nums[t] <= limit) {
                    _m = nums[t];
                    mi = t;
                    t++;
                }
                else {
                    h = Mi+1;
                    _M = nums[h];
                    Mi = h;
                    for (int i=h; i<t; i++) {
                        if (nums[i]>=_M) {
                            _M = nums[i];
                            Mi = i;
                        }
                    }
                }
            }
            if (t-h>ans) ans = t-h;
        }
        return ans;
    }
};

int main() {
    vector<int> nums;
    int limit;
    nums = {8,2,4,7}; limit = 4;
    cout << Solution().longestSubarray(nums, limit) << endl;
    nums = {10,1,2,4,7,2}; limit = 5;
    cout << Solution().longestSubarray(nums, limit) << endl;
    nums = {4,2,2,2,4,4,2,2}; limit = 0;
    cout << Solution().longestSubarray(nums, limit) << endl;

    nums = {}; limit = 4;
    cout << Solution().longestSubarray(nums, limit) << endl;
    nums = {8,2}; limit = 4;
    cout << Solution().longestSubarray(nums, limit) << endl;

    return 0;
}