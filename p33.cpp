#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::iterator cut=nums.end();
        for (auto k=nums.begin()+1;k<nums.end();k++)
            if (*(k-1)>*k) {
                cut=k;
                break;
            }
        auto t=search_n(nums.begin(),cut,1,target);
        auto k=search_n(cut,nums.end(),1,target);
        if (t!=cut) return t-nums.begin();
        if (k!=nums.end()) return k-nums.begin();
        return -1;
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
    vector<int> r={4,5,6,7,0,1,2};
    auto res = Solution().search(r,3);
    cout << res <<endl;
    return 0;
}