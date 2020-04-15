#include "header.h"
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int i;
        int n=nums.size();
        int t=0;
        for (i=0;i<n;) {
            int j=i+1;
            while (j < n && nums[j]==nums[i]) 
                j++;
            number.push_back(nums[i]);
            count.push_back(j-i);
            t++;
            i=j;
        }

        for (i=0;i<t;i++)
            cout << number[i] << " " << count[i] << endl;

        vector<int> tmp;
        dfs(0,t,tmp);

        return res;
    }
    void dfs(int i, int n, vector<int> &tmp) {
        if (i>=n) {
            res.push_back(tmp);
            return;
        }

        for (int k = 0; k <= count[i]; k++)
        {
            dfs(i + 1, n, tmp);
            tmp.push_back(number[i]);
        }
        for (int k = 0; k <= count[i]; k++)
            tmp.pop_back();
    }

private:
    vector<vector<int>> res;
    vector<int> number,count;
};

int main() {
    vector<int> a = {1,2,2};
    auto r = Solution().subsetsWithDup(a);
    for (auto v:r) {
        cout << "[";
        for (auto u:v)
            cout << u << " ";
        cout<<"]" <<endl;
    }
}