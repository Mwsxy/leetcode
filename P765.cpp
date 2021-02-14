#include "header.h"
#include <array>
#include <bits/c++config.h>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
class Solution {
private:
    int getLover(int i) {
        if (i&1) return i-1;
        else return i+1;
    }
public:
#define len 61
    int minSwapsCouples(vector<int>& row) {
        int s[len];
        bool f[len];
        int n;
        n = row.size()/2;
        for (int i=0; i<row.size(); i++)
        {
            s[row[i]]=i;
            f[i] = false;
        }

        int answer = 0;
        for (int i=0; i<n; i++) {
            int a1, a2, j;
            a1 = row[i*2];
            a2 = row[i*2+1];
            if (f[a1]) continue;
            j = getLover(a1);
            while (a2 != j) {
                // printf("%d ", a2);
                a2 = getLover(a2);
                f[a2] = true;
                a2 = row[getLover(s[a2])];
                f[a2] = true;
                answer++;
            }
            // printf("\n");

        }        
        return answer;
    }
};

int main() {
    vector<int> row;
    row = {0, 2, 1, 3};
    cout << Solution().minSwapsCouples(row) << endl;
    row = {3, 2, 0, 1};
    cout << Solution().minSwapsCouples(row) << endl;
    row = {9,12, 2,10, 11,0, 13,6, 4,5, 3,8, 1,7};
    // 4 1 5 6 2 1 0
    // 6 5 0 3 2 4 3

    cout << Solution().minSwapsCouples(row) << endl;

    return 0;
}