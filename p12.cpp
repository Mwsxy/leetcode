#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

string convert(int n,char ten, char half, char one) {
    //0<n<10
    if (n==0 || n>=10) return "";
    if (n<4) return string(n,one);
    if (n==4) return string(1,one)+string(1,half);
    if (n<9) return string(1,half)+string(n-5,one);
    if (n==9) return string(1,one)+string(1,ten);
    return "";
}
class Solution {
public:
    string intToRoman(int num) {
        if (num<1 || num>3999) return "";
        string res="";
        res=res+convert(num/1000,'0','0','M');
        res=res+convert((num%1000)/100,'M','D','C');
        res=res+convert((num%100)/10,'C','L','X');
        res=res+convert((num%10),'X','V','I');

        cout<<res<<endl;
        //string s=to_string(num);
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
    auto res = Solution().intToRoman(1994);
    cout << res <<endl;
    return 0;
}