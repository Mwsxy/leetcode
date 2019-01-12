#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

bool cmp(const string a,const string b) {
    //check if a <= b , return true
    if (a.size()!=b.size()) return (a.size()<b.size());
    for (auto i=0;i<a.size();i++)
        if (a[i]!=b[i]) return a[i]<b[i];
}

class Solution {
public:
    int reverse(int x) {
        string maxInt="2147483647";
        string minInt="2147483648";
        char buff[30];
        bool neg;
        neg = x<0?true:false;
        if (neg) x=-1*x;
        sprintf(buff,"%d",x);
        string s=string(buff);
        for (auto i=0;i<s.size()/2;i++) {
            swap(s[i],s[s.size()-1-i]);
        }
        // cout<<s<<endl;
        bool notOF;
        if (neg) notOF=cmp(s,minInt);
        else notOF=cmp(s,maxInt);
        if (!notOF) return 0;
        sscanf(s.c_str(),"%d",&x);
        if (neg) x=-1*x;
        return x;
    }
};
int main() {
    auto res = Solution().reverse(123);
    cout << res <<endl;
    cout<<"111";
    return 0;
}