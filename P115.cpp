#include "header.h"

class Solution {
public:
    const int len = 1001;
    int numDistinct(string s, string t) {
        int n1,n2;
        n1 = s.length();
        n2 = t.length();
        if (n1<n2) return 0;
        vector<vector<long>> f(n1+1, vector<long>(n2+1));

        for (int i=0; i<=n1; i++)
            f[i][n2] = 1;

        for (int i = n1-1; i >=0; i--) {
            for (int j = n2-1; j >=0; j--) {
                if (s[i] == t[j]) {
                    f[i][j] = f[i+1][j+1]+f[i+1][j];
                }
                else 
                    f[i][j] = f[i+1][j];
            }
        }
        return f[0][0];
    }
};

int main() {
    string s,t;
    s = "rabbbit";
    t = "rabbit";
    cout << Solution().numDistinct(s, t) << endl;
    s = "babgbag";
    t = "bag";
    cout << Solution().numDistinct(s, t) << endl;
    return 0;
}