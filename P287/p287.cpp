#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int left = 1;
        int right = n;
        int mid;
        int lessmid;
        int moremid;
        int eqmid;
        bool d;
        while (left<=right) {
            lessmid=moremid=eqmid=0;
            mid=(left+right)/2;
            if ((left+right)&1==1) d=true;else d=false;
            for (auto v:nums) 
                if (v>=left && v<=right) {
                    if (v<mid) lessmid++;
                    else if (v>mid) moremid++;
                    else eqmid++;
                    if (v==mid && d==true) lessmid++;
                }
            if (eqmid>1) return mid;
            if (lessmid<moremid) left=mid+1;
            else right=mid;
        }
        return mid;

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
    vector<int> nums={4,3,1,4,2};
    auto res = Solution().findDuplicate(nums);
    cout << res << endl;
    return 0;
}