#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool f=false;
        f=next_permutation(nums.begin(),nums.end());
        return;
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
    vector<int> a={3,2,1};
    Solution().nextPermutation(a);
    cout << a[0]<<a[1]<<a[2] <<endl;
    cout<<endl;
    return 0;
}