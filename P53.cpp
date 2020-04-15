#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int tmp=0;
        int m=nums[0];
        for (auto v:nums) {
            if (tmp+v<0) {
                tmp=0;
            }
            else {
                tmp+=v;
                if (tmp>sum) sum=tmp;
            }
            if (v>m) m=v;
        }
        if (m<0) sum=m;
        return sum;
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
    vector<int> a={-1,-1};
    auto res = Solution().maxSubArray(a);
    cout << res <<endl;
    return 0;
}