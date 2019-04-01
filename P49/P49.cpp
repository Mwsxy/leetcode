#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<cstdlib>
#include<cstring>
using namespace std;


    typedef struct {
        string s;
        string str;
    } DS;

    bool cmp(const DS &a,const DS &b) {
        if (a.s.size()!=b.s.size()) return a.s.size()<b.s.size();
        for (int i=0;i<a.s.size();i++)
            if (a.s[i]!=b.s[i]) return a.s[i]<b.s[i];
        return false;
    }
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        vector<DS> a;
        DS t;
        for (auto v:strs) {
            t.s=t.str=v;
            sort(t.s.begin(),t.s.end());
            a.push_back(t);
        }
        sort(a.begin(),a.end(),cmp);
        int i=1,n=0;
        ret.push_back({a[0].str});
        n++;
        while (i<a.size()) {
            if (a[i].s.compare(a[i-1].s)==0) {
                ret[n-1].push_back(a[i].str);
            }
            else {
                ret.push_back({a[i].str});
                n++;
            }
            i++;
        }
        // for (auto v:a)
        //     cout<<v.s<<" ";
        // cout<<endl;
        return ret;
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
     vector<string> a= {"eat", "tea", "tan", "ate", "nat", "bat"};

    string s="abc";
    cout<<s.compare("1bc")<<endl;
    // vector<string> a= {""};
    auto res = Solution().groupAnagrams(a);
    for (auto i:res) {
        for (auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}