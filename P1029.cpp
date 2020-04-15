#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;


bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[2]!=b[2]) return a[2]>b[2];
    int ma,mb;
    ma=min(a[0],a[1]);
    mb=min(b[0],b[1]);
    if (ma!=mb) return ma<mb;
    return false;
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int diff;
        for (auto &v:costs) {
            diff=abs(v[0]-v[1]);
            v.push_back(diff);
        }
        sort(costs.begin(),costs.end(),cmp);
        int n,l,r,i;
        n=costs.size()/2;
        l=r=i=0;
        int ans=0;
        while (l<n || r<n) {
            if (costs[i][0]<=costs[i][1]) {
                if (l<n) {
                    ans+=costs[i][0];
                    l++;
                }
                else {
                    ans+=costs[i][1];
                    r++;
                }
            }
            else {
                if (r<n) {
                    ans+=costs[i][1];
                    r++;
                }
                else {
                    ans+=costs[i][0];
                    l++;
                }
            }
            i++;
        }
        return ans;
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


