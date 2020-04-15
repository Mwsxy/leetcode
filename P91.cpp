#include "header.h"
class Solution {
public:
    int numDecodings(string s) {
        f = vector<int>(s.length());
        return check(s, 0, s.length());
    }
    int check(string &s, int i, int n) {
        if (i>=n) {
            return 1;
        }
        if (f[i]!=0) return f[i];
        int ans=0,t;
        if (s[i]!='0') 
            ans += check(s,i+1,n);
        if (i+1<n) {
            if (s[i]=='1') 
                t = check(s,i+2,n);
            else if (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6')
                t = check(s,i+2,n);
            else 
                t = 0;
            ans += t;
        }
        f[i] = ans;
        return ans;
    }
private:
    vector<int> f;
};

int main() {
    string s="226";
    cout << Solution().numDecodings(s) <<endl;
}