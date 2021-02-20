#include "header.h"
#include <array>
#include <vector>

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dif(K,0);
        int s=0;
        int ret=0;
        for(int i=0;i<n;i++){
            s+=dif[i%K];
            if( (s+A[i])%2==0 ){
                if(i+K>n){
                    return -1;
                }
                dif[i%K]=1;
                ret++;
                s++;
            }
            else 
                dif[i%K]=0;
        }
        return ret;
    }
};

int main() {
    vector<int> A;
    int K;
    A = {0, 1, 0}; K=1;
    cout << Solution().minKBitFlips(A, K) << endl;

    A = {1, 1, 0}; K=2;
    cout << Solution().minKBitFlips(A, K) << endl;

    A = {0,0,0,1,0,1,1,0}; K=3;
    cout << Solution().minKBitFlips(A, K) << endl;
    A = {0,1,1,1,0,1,1,1,0,0,0,0}; K=3;//6
    cout << Solution().minKBitFlips(A, K) << endl;
    A = {1}; K=1;
    cout << Solution().minKBitFlips(A, K) << endl;
    return 0;
}