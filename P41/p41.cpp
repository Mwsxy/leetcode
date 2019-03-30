class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if (n<=0) return 1;
        vector<bool> a(n,true);
        for (auto v:nums)
            if (v>=1 && v<=n) a[v-1]=false;
        int i;
        for (i=0;i<n;i++)
            if (a[i]) break;
        return i+1;
    }
};