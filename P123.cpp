#include "header.h"
#include <vector>

class Solution {
public:
    int maxProfit_once(vector<int>& prices, int &mi, int &mj) {
        int _min, ans =0;
        int i=0;
        if (prices.empty()) return 0;
        _min = 0;
        while (i<prices.size()) {
            if (prices[i] < prices[_min]) {
                _min = i;
            }
            int j=i;
            while (j+1<prices.size() && prices[j+1]>prices[j]) j++;
            if (prices[j]-prices[_min] > ans) {
                ans = prices[j]-prices[_min];
                mi = _min;
                mj = j;
            }
            i=j+1;
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        int _max, _min, ans =0;
        int i=0;
        int mi, mj;
        ans = maxProfit_once(prices, mi, mj);
        if (ans >0) {
            vector<int> sub1(prices.begin(), prices.begin()+mi);
            vector<int> sub2(prices.begin()+mj+1, prices.end());
            int t1,t2;
            // cout << mi << " " << mj << endl;
            t1 = maxProfit_once(sub1, mi, mj);
            t2 = maxProfit_once(sub2, mi, mj);
            ans += max(t1,t2);
        }
        return ans;
    }
};

int main() {
    vector<int> a = {3,3,5,0,0,3,1,4};
    cout << (Solution().maxProfit(a)==6) << endl;
    a = {1,2,3,4,5};
    cout << (Solution().maxProfit(a)==4) << endl;
    a = {7,6,4,3,1};
    cout << (Solution().maxProfit(a)==0) << endl;
    a = {1};
    cout << (Solution().maxProfit(a)==0) << endl;
    a = {2,4,1};
    cout << (Solution().maxProfit(a)==2) << endl;
    a = {6,1,3,2,4,7};
    cout << (Solution().maxProfit(a)) << endl;
}
