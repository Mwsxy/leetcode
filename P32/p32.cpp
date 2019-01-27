#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st,r;
        int t=0;
        for (int i=0;i<s.size();i++) 
            if (s[i]=='(') {
                st.push(i);
            }
            else {
                if (st.empty()) continue;
                else {
                    r.push(st.top());
                    r.push(i);
                    st.pop();
                }
            }
        if (r.empty()) return 0;
        int ans=0;
        int left,right;
        int temp;
        int last=0;
        t=r.top();//t=right  t is previous left
        do {
            right=r.top();r.pop();
            left=r.top();r.pop();
            temp=right-left+1;
            if (t-1==right) temp+=last;
            else if (left>t) continue;
            last=temp;
            t=left;
            if (temp > ans) ans=temp;
        } while (!r.empty());
        return ans;
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
    string s;
    cin>>s;
    auto res = Solution().longestValidParentheses(s);
    cout << res <<endl;
    return 0;
}