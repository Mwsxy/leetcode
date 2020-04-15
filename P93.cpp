#include "header.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        size_t n = s.length();
        size_t d[5];
        d[0] = 0;
        d[4] = n;
        for (d[1] = d[0] + 1; d[1] < min(n,d[0]+4); ++d[1])
            for (d[2] = d[1] + 1; d[2] < min(n,d[1]+4); ++d[2])
                for (d[3] = d[2] + 1; d[3] < min(n,d[2]+4); ++d[3]) {
                    if ((d[1]-d[0]>1 && s[d[0]]=='0') 
                        || (d[2]-d[1]>1 && s[d[1]]=='0')
                        || (d[3]-d[2]>1 && s[d[2]]=='0')
                        || (d[4]-d[3]>1 && s[d[3]]=='0'))
                        continue;
                    string sub[4];
                    for (int i = 0; i < 4; ++i)
                        sub[i]=s.substr(d[i],d[i+1]-d[i]);
                    bool ok = true;
                    for (int i = 0; i < 4; ++i) {
                        int k;
                        sscanf(sub[i].c_str(),"%u",&k);
                        if (k<0 || k>255) {
                            ok=false;
                            break;
                        }
                    }
                    if (ok) {
                        string ans=sub[0];
                        for (int i=1;i<4;++i)
                            ans+="."+sub[i];
                        cout<<ans<<endl;
                        ret.push_back(ans);
                    }
                }
        return ret;
    }
};

int main() {
    Solution().restoreIpAddresses("0000");
    Solution().restoreIpAddresses("25525511135");
    Solution().restoreIpAddresses("256256256256");
    Solution().restoreIpAddresses("010010");
    Solution().restoreIpAddresses("1111");
    return 0;
}
