#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();



class Solution {
public:
    bool isMatch(string s, string p) {
        
        s+='1';p+='1';

        int l1=s.length(),l2=p.length();
        // cout << s << "  |  " << p << endl;

        bool **f = (bool**)malloc(sizeof(bool*)*(l2+1));
        for (int i=0;i<=l2;i++) {
            f[i]=new bool [l1+1];
            for (int j=0;j<=l1;j++)
                f[i][j]=false;
        }
        f[0][0]=true;
        for (int i=0;i<l2;i++) {
            for (int j=0;j<l1;j++) {
                if (!f[i][j]) continue;
                if (p[i]=='*') {
                    for (int k=j;k<=l1;k++) 
                        f[i+1][k]=true;
                }
                else if (p[i]=='?' || s[j]==p[i]) {
                    f[i+1][j+1]=true;
                }
            }
        }
        // for (int i=0;i<=l2;i++) {
        //     for (int j=0;j<=l1;j++)
        //         cout << f[i][j] << " ";
        //     cout<<endl;
        // }
        return f[l2][l1];
    }
};

int main() {
    auto res = Solution().isMatch("",
"*");
    cout << res <<endl;
    return 0;
}