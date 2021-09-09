#include "header.h"

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        answer = 0;
        dfs(nums, 0, 0);
        return answer;
    }
    int answer;
    int a[4];
    void dfs(vector<int> &nums, int depth, int i0)
    {
        if (depth>=4)
        {
            if (a[0]+a[1]+a[2] == a[3])
                answer++;
            return;
        }
        for (int i=i0; i<nums.size(); i++)
        {
            a[depth] = nums[i];
            dfs(nums, depth+1, i+1);
            // if (depth==0)
            //     dfs(nums, depth+1, i+1);
            // else if (depth>0 && a[depth]>a[depth-1])
            //     dfs(nums, depth+1, i+1);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> inp;
    int r;
    inp = {1,2,3,6};
    r = sol.countQuadruplets(inp);
    cout << r << endl;

    inp = {3,3,6,4,5};
    r = sol.countQuadruplets(inp);
    cout << r << endl;


    inp = {1,1,1,3,5};
    r = sol.countQuadruplets(inp);
    cout << r << endl;    


    inp = {28,8,49,85,37,90,20,8};
    r = sol.countQuadruplets(inp);
    cout << r << endl;   
    return 0;
}