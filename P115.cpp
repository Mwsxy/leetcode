#include "header.h"

class Solution {
public:
    const int len = 1001;
    int numDistinct(string s, string t) {
        int n1,n2;
        n1 = s.size();
        n2 = t.size();
        if (n1<n2) return 0;
        int f[len][len];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n2; i++) {
            for (int j = i; j < n1; j++) {
                f[i][j] = max(f[i][j], f[i-1][j]);
                if (s[j] == t[i]) {
                    f[i][j] = max(f[i][j], f[i-1][j-1]);
                }
            }
        }
    }
};

int main() {
    return 0;
}