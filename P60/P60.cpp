#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int *factorial;
        bool *flag;
        factorial = new int [n];
        flag = new bool [n];
        factorial[0]=1;
        flag[0]=false;
        for (int i=1;i<n;i++) {
            factorial[i]=factorial[i-1]*i;
            flag[i]=false;
        }
        k--;
        int a;
        string s;
        for (int i=n-1;i>=0;i--) {
            a=judge(k/factorial[i],flag);
            s+=to_string(a+1);
            k%=factorial[i];
        }
        return s;
    }
private:
    int judge(int x,bool f[]) {
        // there is x nums smaller than the returns
        // the f[i]==true means i has used
        int i,s;
        i=s=0;
        while (s<x) {
            if (!f[i]) s++;
            i++;
        }
        while (f[i]) {
            i++;
        }
        f[i]=true;
        return i;
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
    auto res = Solution().getPermutation(4,9);
    cout << res <<endl;
    return 0;
}