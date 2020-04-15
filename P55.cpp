#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far,i,dest;
        if (nums.empty()) return false;
        dest=nums.size()-1;
        i=0;
        far=0;
        while (i<=far && far<dest) {
            if (i+nums[i]>far) far=i+nums[i];
            i++;
        }
        return far>=dest;
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
    vector<int> a={2,3,1,1,4};
    auto res = Solution().canJump(a);
    cout << res <<endl;
    return 0;
}