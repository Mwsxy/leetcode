#include "header.h"
#include <array>
#include <cstring>
#include <ostream>
#include <string>

class Solution {
private:
    int dfs(const string& s, int l, int r, int k) {
        array<int, 26> cnt;
        cnt.fill(0);
        int i;
        for (i=l; i<=r; i++)
            cnt[s[i]-'a']++;
        char split = 0;
        for (i=0; i<26; i++) {
            if (cnt[i]>0 && cnt[i]<k) {
                split = i+'a';
                break;
            }
        }
        if (split==0) return r-l+1;
        i=l;
        int ret =0;
        while (i<=r) {
            while (i<=r && s[i]==split) i++;
            if (i>r) break;
            int start =i;
            while (i<=r && s[i]!=split) i++;
            int &&len = dfs(s, start, i-1, k);
            ret = max(ret, len);
        }
        return ret;
    }
public:
    int longestSubstring(string s, int k){
        return dfs(s, 0, s.length()-1, k);
    } 
};

int main() {
    string s;
    int k;
    s = "aaabb";
    k = 3;
    cout << Solution().longestSubstring(s, k) << endl;

    s = "ababbc";
    k=2;
    cout << Solution().longestSubstring(s, k) << endl;
    s = "bbaaacbd";
    k=3;
    cout << Solution().longestSubstring(s, k) << endl;
    
    s = "aaaaaaaaabbbcccccddddd";
    k=5;
    cout << Solution().longestSubstring(s, k) << endl;
    s = "zzzzzzzzzzaaaaaaaaabbbbbbbbhbhbhbhbhbhbhicbcbcibcbccccccccccbbbbbbbbaaaaaaaaafffaahhhhhiaahiiiiiiiiifeeeeeeeeee";
    k = 10;
    cout << Solution().longestSubstring(s, k) << endl;
    return 0;
}