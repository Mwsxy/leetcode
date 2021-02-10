#include "header.h"
#include <cstddef>
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        array<int, 100001> max1, max2;
        size_t _min, _max;
        int ans;
        if (prices.empty()) return 0;
        _min = _max = 0;
        ans = 0;
        for (size_t i=0; i<prices.size(); i++) {
            if (prices[i] < prices[_min]) {
                _min = i;
                _max = i;
            }
            if (prices[i] > prices[_max]) {
                _max = i;
            }
            if (prices[_max] - prices[_min] > ans ) {
                ans = prices[_max] - prices[_min];
            }
            max1[i] = ans;
        }
        int one_max = ans;
        ans = 0;
        _min = _max = prices.size()-1;
        for (int i=prices.size()-1; i>=0; i--) {
            if (prices[i] > prices[_max]) {
                _max = i;
                _min = i;
            }
            if (prices[i] < prices[_min]) {
                _min = i;
            }
            if (prices[_max] - prices[_min] > ans ) {
                ans = prices[_max] - prices[_min];
            }
            max2[i] = ans;
        }
        for (size_t i=0; i<prices.size()-1; i++) 
            ans = max(ans, max1[i]+max2[i+1]);
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
