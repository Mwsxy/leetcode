#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> f={target};
        auto j=find_first_of(nums.begin(),nums.end(),f.begin(),f.end());
        auto k=find_end(nums.begin(),nums.end(),f.begin(),f.end());
        int it1=j==nums.end()?-1:j-nums.begin();
        int it2=k==nums.end()?-1:k-nums.begin();
        return {it1,it2};
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
    auto res = Solution().xxx;
    cout << res <<endl;
    return 0;
}