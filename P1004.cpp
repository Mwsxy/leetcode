#include "header.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int h,t;
        h=t=0;
        int k=0, ans=0;
        while (t<A.size()) {
            if (A[t]==1) {
                t++;
            }
            else if (k<K) {
                k++;
                t++;
            } else {
                if (A[h]==0) k--;
                h++;
            }
            ans = max(ans, t - h);
        }
        return ans;
    }
};

int main() {
    vector<int> A;
    int K;
    A = {1,1,1,0,0,0,1,1,1,1,0}; K=2;
    cout << Solution().longestOnes(A, K) << endl;
    A = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; K=3;
    cout << Solution().longestOnes(A, K) << endl;
    A = {0,0}; K=2;
    cout << Solution().longestOnes(A, K) << endl;
    A = {0}; K=2;
    cout << Solution().longestOnes(A, K) << endl;
    A = {}; K=2;
    cout << Solution().longestOnes(A, K) << endl;
    A = {1,1,1,1,1}; K=2;
    cout << Solution().longestOnes(A, K) << endl;
    return 0;
}