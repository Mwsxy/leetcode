#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative=false;
        negative = (dividend ^ divisor) <0;
        unsigned int ans=0;
        unsigned int t=dividend>=0?dividend:~dividend+1;
        unsigned int d=divisor>=0?divisor:~divisor+1;
        for (int i=31; i>=0;i--) {
            if ((t>>i)>=d) {
                ans+=1<<i;
                t-=d<<i;
            }
        }
        if (ans>(negative?0x80000000U:0x7fffffffU)) 
            return 0x7fffffff;
        return negative?~ans+1:ans;
    }
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


int main() {
    auto res = Solution().divide(7,-3);
    cout << res <<endl;
    cout << "stop";
    return 0;
}