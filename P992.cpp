#include "header.h"
#include <array>
#include <bits/c++config.h>
#include <cstddef>
#include <vector>

#define LEN 20001

class Solution {
public:
    array<int, LEN> ls;
    array<int, LEN> found;

    int subarraysWithKDistinct(vector<int>& A, int K) {
        // ls.fill(-1);
        found.fill(-1);
        int total = 0;
        for (size_t i=0; i<A.size(); i++) {
            if (found[A[i]]==-1) {
                ls[i] = -1;
                found[A[i]]=i;
                total++;
            }
            else {
                ls[i] = found[A[i]];
                found[A[i]] = i;
            }
        }
        for (size_t i=0; i<A.size(); i++)
            cout <<ls[i] << " ";
        cout << endl;

        if (total<K) return 0;

        int ans = 0;
        for (size_t i=0; i<A.size(); i++) {
            int nums=0;
            for (size_t k=1; k<=A.size(); k++) {
                // [i, i+k)
                int j=i+k-1;
                if (j>=A.size()) break;
                if (ls[j]==-1 || ls[j]<i) nums++;
                if (nums == K) {
                    ans++;
                    cout << i <<" " << j << endl;
                }
            }            
        }
        return ans;
    }

};

int main() {
    vector<int> a;
    int K;
    a={1,2,1,2,3}; K=2;
#define RUN cout << Solution().subarraysWithKDistinct(a, K) <<endl
    RUN;
    a = {1,2,1,3,4}; K=3;
    RUN;
    a = {2,1,2,1,2}; K=2;
    RUN;
    return 0;
}