#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (divisor==1) return dividend;

        bool negative=false;
        negative = (dividend ^ divisor) <0;
        unsigned int ans=0;
        unsigned int t=dividend>=0?dividend:~dividend+1;
        unsigned int d=divisor>=0?divisor:~divisor+1;
        if (t<d) return 0;
        if (d==1) ans=t;
        else
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
    auto res = Solution().divide(-2147483648,-2);
    cout << res <<endl;
    cout << "stop";
    return 0;
}