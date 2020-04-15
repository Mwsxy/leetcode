#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        unsigned long long lld=0;
        vector<int> res;
        for (unsigned long long i=1;i<=(1ULL<<n);i++) {
            res.push_back(lld);
            unsigned long long tmp;
            tmp = ((i^(i-1))>>1)+1;
            lld=lld^(tmp);
        }
        // for (int i=0;i<1<<n;i++)
        //     cout << res[i] <<" ";
        // cout <<endl;
        return res;
    }
};

int main() {
    Solution().grayCode(3);
    return 0;
}