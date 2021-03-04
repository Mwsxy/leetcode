#include "header.h"
#include <algorithm>
#include <vector>

class Solution {
public:
    static bool less(vector<int> &a, vector<int> &b) {
        if (a[0]!=b[0]) 
            return a[0]<b[0];
        else 
            return a[1]<b[1];
    }
    int maxEnvelopes_n2(vector<vector<int>>& envelopes) {
        int ans = 0;
        if (!envelopes.empty()) ans = 1;
        sort(envelopes.begin(), envelopes.end(), less);
        vector<int> f(envelopes.size(), 1);
        for (int i=0; i<envelopes.size(); i++) {
            for (int j=0; j<i; j++) {
                if (envelopes[j][0]<envelopes[i][0]) {
                    if (envelopes[j][1]<envelopes[i][1]) {
                        if (f[j]+1>f[i]) {
                            f[i] = f[j]+1;
                            ans = max(ans, f[i]);
                        }
                    }
                }
                else 
                    break;
            }
        }
        return ans;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {//nlogn
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), 
            [](const auto &a, const auto &b) {
                return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
            });
        vector<int> f = {envelopes[0][1]};
        for (int i=0; i<envelopes.size(); i++) {
            if (int num = envelopes[i][1]; num>f.back())
                f.push_back(num);
            else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }
};

int main() {
    vector<vector<int>> a = {{5,4},{6,4},{6,7},{2,3}};
    // vector<vector<int>> a = {};
    cout << Solution().maxEnvelopes(a)<<endl;
    return 0;
}