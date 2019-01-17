#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>::iterator left,right;
        int res=nums[0]+nums[1]+nums[2];
        for (auto v=nums.begin()+1;v<nums.end()-1;v++) {
            left=nums.begin();
            right=nums.end()-1;
            while (left<right) {
                auto i=*left+*v+*right;
                if (abs(i-target)<abs(res-target)) res=i;
                if (i>target) right--;
                else if (i<target) left++;
                else return target;
                if (v==left) left++;
                if (v==right) right--;
            }
        }
        return res;
    }
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


int main() {
    vector<int> nums={-1,-2,-5,3,-4};
    int target=-1;
    auto res = Solution().threeSumClosest(nums,target);
    cout << res <<endl;
    return 0;
}