#include "header.h"
#include <vector>

class Solution {
public:
    vector<int> sum;
    inline int getSum(int l, int r) {
        return sum[l+1]-sum.front() + sum.back()-sum[r];
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        sum.resize(n+1);
        sum[0] = 0;
        for (int i=0; i<n; i++) {
            sum[i+1] = sum[i] + cardPoints[i];
        }
        
        int ans = 0;
        int left, right;
        for (int i=0; i<=k; i++) {
            left = k-1-i;
            right = n-i;
            int t;
            t = getSum(left, right);
            if (t>ans) ans = t;
        }
        return ans;
    }
};

int main() {
    vector<int> a = {1,2,3,4,5,6,1};
    int k;
    cout << Solution().maxScore(a, 3) << endl;
    a={2,2,2};k=2;
    cout << Solution().maxScore(a, k) << endl;
    a={9,7,7,9,7,7,9};k=7;
    cout << Solution().maxScore(a, k) << endl;
    a={1,1000,1};k=1;
    cout << Solution().maxScore(a, k) << endl;
    a={1,79,80,1,1,1,200,1};k=3;
    cout << Solution().maxScore(a, k) << endl;
    return 0;
}