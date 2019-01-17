#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> kb = {"",
                    "", "abc", "def",
                    "ghi", "jkl", "mno",
                    "pqrs", "tuv", "wxyz"};
    void f(string digits, string s, vector<string> &res) {
        if (digits.size()==0) {
            if (s.size()!=0) res.push_back(s);
            return;
        }
        auto set=kb[digits[0]-'0'];
        if (set.size()!=0)
            for (auto v:set) {
                f(digits.substr(1),s+v,res);
            }
        else f(digits.substr(1),s,res);
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        f(digits,"",res);
        return res;
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
    auto res = Solution().letterCombinations("23");
    for (auto v:res)
        cout << v <<endl;
    return 0;
}