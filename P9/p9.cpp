#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;



bool check(string s) {
    int i=0;
    int j=s.size()-1;
    while (s[i]==s[j]) {
        i++;
        j--;
        if (i>=j) return true;
    }
    return false;
}

class Solution {
public:
    bool isPalindrome(int x) {
        return x<0?false:check(to_string(x));
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
    auto res = Solution().isPalindrome(0);
    cout << res <<endl;
    return 0;
}