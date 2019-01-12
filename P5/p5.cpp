#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool check(string s) {
    auto i=0;
    auto j=s.size()-1;
    while (s[i]==s[j]) {
        i++;
        j--;
        if (i>=j) return true;
    }
    return false;
}


class Solution {
public:
    string longestPalindrome(string s) {
        const int size=1000;
        int **f;
        string res=string("");
        f=new int*[s.size()+1];
        for (auto i=0;i<=s.size();i++){
            f[i]=new int[s.size()+1];
            f[i][1]=1;
            f[i][0]=0;
        }
        res+=s[0];
        string t;
        for (auto k=2;k<=s.size();k++) { // length
            
            for (auto i=0;i<=s.size()-k;i++) { //begin i  , end i+k
                if (s[i]==s[i+k-1] && (f[i+1][k-2]==k-2)) {
                    f[i][k]=max(f[i][k],f[i+1][k-2]+2);
                    t=s.substr(i,k);
                    if (t.size()>res.size()) res=t;
                    //cout<<i<<" "<<k<<" "<<t<<endl;
                }
            }
        }
         return res;   
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s);
    return 0;
}
