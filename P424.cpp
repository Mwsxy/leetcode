#include "header.h"

#define N 10001

class Solution {
public:
    int characterReplacement(string s, int k) {
        static int f[N][N];
        memset(f, 0, sizeof(f));
        for (size_t i = 0; i < s.size(); i++)
        {
            f[i][0] = 1;
            if (i>0 && s[i]==s[i-1]) 
                f[i][0] = f[i-1][0]+1;
        }
        for (size_t j=1; j<=k; j++) {
            for (size_t i = 0; i < s.size(); i++) {
                f[i][j] = max(f[i][j], f[i][j-1]);
                if (i>0) {
                    f[i][j] = max(f[i][j], f[i-1][j-1]+1);
                    if (s[i]==s[i-1])
                        f[i][j] = max(f[i][j], f[i-1][j]+1);
                }
            }
        }
        for (int j=0; j<=k; j++) {
            for (size_t i = 0; i < s.size(); i++)
                cout << f[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return 0.;
    }
};

int main(int argc, char const *argv[])
{
    string s = "AAABBBABCAABVC";
    int k = 4;
    cout << Solution().characterReplacement(s,k);
    return 0;
}
