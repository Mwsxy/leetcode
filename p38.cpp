#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        string next;
        int i,cnt;
        while (n>1) {
            i=0;next="";
            while (i<s.size()) {
                cnt=1;
                
                while (i+1<s.size() && s[i+1]==s[i]) {
                    i++;
                    cnt++;
                }
                next+=to_string(cnt)+s[i];
                i++;
            }
            s=next;
            n--;
        }
        return s;
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
    auto res = Solution().xxx;
    cout << res <<endl;
    return 0;
}