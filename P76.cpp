#include "header.h"

class Solution {
public:
    using mmap = map<char, int>;
    // using mmap = unordered_map<char, int>;
    mmap ori, cnt;
    static inline void add(mmap& m, char c)
    {
        if (m.count(c)>0)
            ++m[c];
        else
            m[c] = 1;
    }
    static inline void del(mmap& m, char c)
    {
        if (m.count(c)>0)
            --m[c];
        else
            m[c] = 0;
    }
    inline bool check()
    {
        for (auto kv : ori)
        {
            if (cnt.count(kv.first)==0 || cnt[kv.first]<kv.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {

        for (auto v:t)
        {
            add(ori, v);
        }
        int l,r,n;
        l = 0; r = -1;
        n = static_cast<int>(s.size());
        pair<int, int> ans(0, 0);
        int minSize = INT_MAX;
        while (l < n)
        {
            while (r+1<n)
            {
                r++;
                if (ori.count(s[r])>0)
                {
                    add(cnt, s[r]);
                    if (check())  {
                        // cout << "l r = " << l << " " << r << endl;
                        if (r-l+1<minSize)
                        {
                            minSize = r-l+1;
                            ans = make_pair(l, minSize);
                        }
                        break;
                    }
                }
            }
            bool ok = check();
            while (l<=r)
            {
                if (ori.count(s[l])>0)
                {
                    del(cnt, s[l]);
                    ok = check();
                }
                l++;
                if (ok) 
                {
                    if (r-l+1 < minSize)
                    {
                        minSize = r-l+1;
                        ans = make_pair(l, minSize);
                    }
                }
                else
                    break;
            }   
        }
        // cout << ans.first << " " << ans.second << endl;
        return s.substr(ans.first, ans.second);
    }
};


int main()
{
    string s, t;
    s = "ab"; t = "a";
    s = "bdab"; t = "ab";
    s = "cabefgecdaecf"; t = "cae";
    cout << Solution().minWindow(s, t) <<endl;
    return 0;
}