#include "header.h"
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int _max, _min, ans =0;
        int i=0;
        while (i<prices.size()) {
            int j=i;
            while (j+1<prices.size() && prices[j+1]>prices[j]) j++;
            if (j>i) {
                ans += prices[j]-prices[i];
            }
            i=j+1;
        }
        return ans;
    }
};

int main() {
    vector<int> a = {1,2,3,4,5};
    cout << Solution().maxProfit(a) << endl;
    a = {7,1,5,3,6,4};
    cout << Solution().maxProfit(a) << endl;
    a = {7,6,4,3,1};
    cout << Solution().maxProfit(a) << endl;
    a = {7,1,10,10,100,50,200};
    cout << Solution().maxProfit(a) << endl;
    return 0;
}