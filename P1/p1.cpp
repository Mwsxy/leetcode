#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto i=nums.begin();
        auto j=i;
        int x,y;
        x=y=0;
        for ( ;i!=nums.end();i++) {
            auto j=i+1;
            y=x+1;
            for (;j!=nums.end();j++) {
                if (*i+*j==target) {
                    return {x,y};
                }
                y++;
            }
            x++;
        }
        return {0,0};
    }
};


int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto a=new(Solution);
    auto b=(a->twoSum(nums,target));
    for (auto &i:b)
        cout<<i<<" ";
    return 0;
}