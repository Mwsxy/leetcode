#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;
int convert(char pos,char next) {
    int c[256];
    c['I']=1;       c['V']=5;       c['X']=10;
    c['L']=50;      c['C']=100;     c['D']=500;
    c['M']=1000;
    int res=0;
    int neg=1;
    if ((pos=='I' && next=='V') ||
        (pos=='I' && next=='X') ||
        (pos=='X' && next=='L') ||
        (pos=='X' && next=='C') ||
        (pos=='C' && next=='D') ||
        (pos=='C' && next=='M'))
        neg=-1;
    return c[pos]*neg;
}
class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        s=s+'0';
        for (auto i=0;i<s.size()-1;i++)
            res+=convert(s[i],s[i+1]);
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
    auto res = Solution().romanToInt("LVIII");
    cout << res <<endl;
    return 0;
}