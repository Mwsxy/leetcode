#include "header.h"
#include <string>
#include <vector>

class Solution {
public:
#define len 2001
    bool f[len][len];
    vector<vector<string>> ret;
    vector<vector<string>> partition(string s) {
        memset(f, 0, sizeof(f));
        for (int k=1; k<=s.size(); k++) {
            for (int i=0; i<s.size(); i++) {
                int j = i+k-1;
                if (j>=s.size()) break;
                if (k==1) {
                    f[i][k]=true;
                }
                else if (k==2) {
                    if (s[i]==s[j]) f[i][k]=true;
                }
                else if (s[i]==s[j] && f[i+1][k-2]) {
                    f[i][k]=true;
                }
            }
        }
        vector<pair<int, int>> sub;
        dfs(s, 0, sub);
        return ret;
    }
    
    void dfs(string &s, int i, vector<pair<int, int>> &sub) {
        if (i>=s.size()) {
            vector<string> set;
            for (auto a:sub) {
                string st = s.substr(a.first, a.second);
                set.push_back(st);
            }
            ret.push_back(set);
            return;
        }
        for (int k=1; k<=s.size()-i; k++) {
            int j=i+k-1;
            sub.emplace_back(i,k);
            if (f[i][k]) dfs(s, j+1, sub);
            sub.pop_back();
        }
    }
};

int main() {
    string st;
    st = "aaaaaaaaaaabbbbbbbb";
    auto ret = Solution().partition(st);
    for (auto set:ret) {
        for (auto s:set) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}