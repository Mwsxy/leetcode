#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _max, _min, ans =0;
        int i=0;
        _min = prices[0];
        while (i<prices.size()) {
            if (prices[i] < _min) _min = prices[i];
            int j=i;
            while (j+1<prices.size() && prices[j+1]>prices[j]) j++;
            if (prices[j]-_min > ans) ans = prices[j]-_min;
            i=j+1;
        }
        return ans;
    }
};
