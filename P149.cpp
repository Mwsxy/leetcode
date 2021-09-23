#include "header.h"

class Solution {
public:
    bool online(const vector<int>& a, const vector<int>& b, const vector<int>& c)
    {
        int ab0,ab1,ac0,ac1;
        ab0 = b[0] - a[0]; ab1 = b[1] - a[1];
        ac0 = c[0] - a[0]; ac1 = c[1] - a[1];
        return ab0*ac1 == ab1*ac0;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = min<int>(points.size(), 2);
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int sum = 2;
                for (int k=j+1; k<n; k++)
                {
                    if (online(points[i], points[j], points[k]))
                        sum++;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};