#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find_first_of(needle);

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
    auto res = Solution().strStr("XXXxxXX","Xx");
    cout << res <<endl;
    return 0;
}