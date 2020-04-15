#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

int Match(string s,string p) {
    int i,j;
    i=j=0;
    bool regex;
    //cout<<s<<endl<<p<<endl;
    while (i<s.size() && j<p.size()) {
        regex=false;
        if (j+1<p.size() && p[j+1]=='*') 
            regex=true;
        if (regex==false) {
            if (p[j]=='.' || s[i]==p[j]) {
                i++;j++;
            }                
            else 
                return i;
        } 
        else {
            //*
            char prev=p[j];
            for (auto rep=0;rep<=s.size()-i;rep++) {
                string tmp="";
                for (auto k=0;k<rep;k++) tmp+=prev;
                //cout<<tmp<<endl;
                auto res=Match(s.substr(i,s.size()-i),tmp+p.substr(j+2,p.size()-j-2));
                if (i+res==s.size()) return s.size();
                else if (res<rep) return i;
            }
            return i;
        }  
    }
    if (j==p.size()) return i;
    else return s.size()+1;
}
class Solution {
public:
    bool isMatch(string s, string p) {
        s+='.';
        p+='.';
        return (s.size()==Match(s,p));
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
    // string s="mississippi";
    // string p="mis*is*.p*.";
    // string s="ab";
    // string p=".*c";
    string s="a";
    string p="ab*";
    auto res = Solution().isMatch(s,p);
    cout << res <<endl;
    cout << "Stop!"<< endl;
    return 0;
}