#include "header.h"
#include <vector>

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int chance = 1;
        int t = 1;
        while (t < nums.size()) {
            if (nums[t - 1] > nums[t]) {
                if (chance > 0) {
                    int _min, _max;
                    if (t - 2 >= 0)
                        _min = nums[t - 2];
                    else 
                        _min = nums[t];
                    if (t + 1 < nums.size())
                        _max = nums[t+1];
                    else
                        _max = nums[t-1];
                    
                    if (max(nums[t-1], nums[t])> _max && 
                        min(nums[t-1], nums[t])< _min)
                        return false;
                    chance--;
                } 
                else
                    return false;
            }
            t++;
        }
        return true;
    }
};

int main() {
    vector<int> a = {3,4,2,3};
    cout << Solution().checkPossibility(a)<<endl;
    a = {4,2,3};
    cout << Solution().checkPossibility(a)<<endl;
    a = {4,2,1};
    cout << Solution().checkPossibility(a)<<endl;
    a = {5,7,1,8};
    cout << Solution().checkPossibility(a)<<endl;
    a = {-1,4,2,3};
    cout << Solution().checkPossibility(a)<<endl;
    return 0;
}