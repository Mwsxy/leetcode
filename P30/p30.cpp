#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool check(string s,vector<string>& words) {
        int wordsLen = words[0].size();
        int n=words.size();
        vector<bool> flag(n,true);
        int i=0,cnt=n;
        bool hit;
        if (s.size()<n*wordsLen) return false;
        while (i<s.size()) {
            string t=s.substr(i,wordsLen);
            //cout << "t:"<<t<<endl;
            hit=false;
            for (int j=0;j<n;j++) 
                if (flag[j] && t.compare(words[j])==0) {
                    flag[j]=false;
                    i+=wordsLen;
                    cnt--;
                    hit=true;
                    break;
                }
            if (hit==false) return false;
            if (cnt==0) return true;
        }
        return false;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        
        int len=s.size();
        vector<bool> b;
        for (int i=0;i<len;i++)
            if (check(s.substr(i),words)) res.push_back(i);

        return res;

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
    vector<string> words={"foo","bar"};
    auto res = Solution().findSubstring("barfoothefoobarman",words);
    for (auto v:res) 
        cout << v <<endl;
    return 0;
}