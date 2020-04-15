#include "header.h"

class Solution {
public:
    int numTrees(int n) {
        if (n<=0) return 1;
        if (n<3) return n;
        if (rec.size()<n) {
            rec=vector<int>(n+1);
        }
        else if (rec[n]!=0)
            return rec[n];
        int nums=0;
        for (int i=0;i<n;++i)
            nums+=numTrees(i)*numTrees(n-1-i);
        rec[n]=nums;
        return nums;
    }
    vector<int> rec;
};

int main() {
    cout << Solution().numTrees(3) << endl;    
    cout << Solution().numTrees(0) << endl;    
    cout << Solution().numTrees(1) << endl;    
    cout << Solution().numTrees(10) << endl;    
}