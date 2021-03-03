#include "header.h"
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1);
        ret[0]=0;
        int cnt = 0;
        for (int x=1; x<=num; x++) {
            ret[x] = ret[(x-1)&x]+1;
        }
        return ret;
    }
};

int main() {
    print(Solution().countBits(5));


    return 0;
}