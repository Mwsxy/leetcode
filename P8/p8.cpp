#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long k=0;
        auto ret = sscanf(str.c_str(),"%lld",&k);
        cout <<ret<<endl;
        if (ret<0) k=0;
        if (k>0x7fffffff) return 0x7fffffff;
        if (k<(int)0x80000000) return 0x80000000;
        return k;
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
    auto res = Solution().myAtoi("words and 987");
    cout << res<<endl;
    return 0;
}