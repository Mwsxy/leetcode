#include "header.h"

class Solution {
public:
    int gcd(int a, int b)
    {
        return a%b?gcd(b,a%b):b;
    }
    int find(vector<int> &f, int x)
    {
        if (f[x]!=x) f[x] = find(f, f[x]);
        return f[x];
    }
    vector<int> hs;

    bool gcdSort(vector<int>& nums) {
        constexpr int maxn = 30005;
        int n = nums.size();
        // vector<vector<int>> h(maxn, vector<int>(maxn, 0));
        
        hs.resize(n);
        for (int i=0; i<n; i++) 
            hs[i]=i;
        vector<int> ord, id;
        for (int i=0; i<n; i++)
        {
            bool tocheck = false;
            for (int j=i+1; j<n; j++)
            {
                if (nums[i] > nums[j])
                    tocheck = true;
                int g = gcd(nums[i], nums[j]);
                // if (h[nums[i]][nums[j]]==0)
                // {
                //     int g = gcd(nums[i], nums[j]);
                //     h[nums[i]][nums[j]] = g;
                //     h[nums[j]][nums[i]] = h[nums[i]][nums[j]];
                // }
                // if (h[nums[i]][nums[j]]>1)
                if (g>1)
                {
                    hs[find(hs, j)] = hs[find(hs, i)];
                }
            }
            if (!tocheck)
            {
                ord.emplace_back(nums[i]);
            }
        }


        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
            {
                if (nums[j]>nums[i]  && find(hs, nums[i]) == find(hs, nums[j]))
                        swap(nums[i], nums[j]);
            }
        for (int i=1; i<n; i++)
            if (nums[i] < nums[i-1])
                return false;
        return true;
    }
};