#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:

    void detect(int n,string s,int stack,vector<string> &res) {
        if (n<0) return;
        if (n==0 && stack==0) {
            res.push_back(s);
            return;
        }
        if (stack>0) {
            detect(n-1,s+'(',stack+1,res);
            detect(n,s+')',stack-1,res);
        } else if (stack==0) {
            detect(n-1,s+'(',stack+1,res);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        detect(n,"",0,res);
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
    auto res = Solution().generateParenthesis(3);
    for (auto k:res)
        cout << k <<endl;
    return 0;
}