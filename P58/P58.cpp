#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string::reverse_iterator v,e;
        if (s.empty()) return 0;
        e=s.rbegin();
        while (e!=s.rend() && *e==' ') e++;
        for (v=e;v!=s.rend()&&*v!=' ';++v);
        return distance(e,v);
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
    auto res = Solution().lengthOfLastWord("world");
    cout << res <<endl;
    return 0;
}