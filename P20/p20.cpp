#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>


using namespace std;

class Solution {
public:
    int convert(char c) {
        if (c=='(') return 1;
        if (c=='[') return 2;
        if (c=='{') return 3;               
        if (c==')') return -1;
        if (c==']') return -2;
        if (c=='}') return -3; 
        return 0;
    }
    bool isValid(string s) {
        stack<int> h;
        for (auto v:s) {
            auto t=convert(v);
            if (t>0) h.push(t);
            else if (h.empty()==false) {
                auto p=h.top();
                if (p+t!=0) return false;
                h.pop();
            }
            else 
                return false;
        }       
        if (h.empty()==true) 
            return true;
        return false;
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
    auto res = Solution().isValid(")");
    cout << res <<endl;
    return 0;
}