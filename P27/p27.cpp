#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int t,n,i;
        i=0;
        n=nums.size()-1;
        while (i<=n) {
            while (nums[i]==val && i<=n) {
                nums[i]=nums[n];
                n--;
            }
            i++;
        }
        return n+1;
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