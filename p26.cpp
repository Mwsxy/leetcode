#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator tail;
        tail = unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),tail));
        return nums.size();
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
    auto res = Solution().removeDuplicates;
    cout << res <<endl;
    return 0;
}