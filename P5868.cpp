#include "header.h"

int gcd(int a, int b)
{
    return a%b?gcd(b,a%b):b;
}
struct hasher
{
    size_t operator() (const pair<int, int> &k) const
    {
        return hash<long>{}(k.first*1e5+k.second);
    }
};
struct comparer
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const 
    {
        return a.first == b.first && a.second == b.second;
    }
};



class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        using int2 = pair<int, int>;
        unordered_map<int2, int, hasher, comparer> table;
        int n = rectangles.size();
        for (int i=0; i < n; i++)
        {
            int w,h;
            w = rectangles[i][0];
            h = rectangles[i][1];
            int g = gcd(w, h);
            while (g>1)
            {
                w /= g;
                h /= g;
                g = gcd(w,h);
            }
            int2 key(w,h);
            if (table.count(key)==0)
            {
                table[key] = 1;
            }
            else
            {
                table[key]+=1;
            }
        }
        long long ans = 0;
        for (auto &ele : table)
        {
            long long val = ele.second;
            ans += val*(val-1)/2;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> inp = {{4,8}, {3,6}, {10,20}, {15,30}};
    cout << Solution().interchangeableRectangles(inp) << "\n";
    return 0;
}