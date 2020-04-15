#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unsigned long flag[3];
        vector<int> tmp;
        vector<vector<int>> ret;
        flag[0]=flag[1]=flag[2]=0;
        DFS(n,0,flag,tmp,ret);
        //convert to string
        vector<vector<string>> s;
        
        for (auto v:ret) {
            vector<string> t;
            for (int i=0;i<n;i++) {
                string d(n,'.');
                // cout<<d<<endl;
                d[v[i]]='Q';
                t.push_back(d);
            }
            s.push_back(t);
        }
        return s;
    }
private:
    void DFS(int n,int level,unsigned long f[3],vector<int> &ans, vector<vector<int>> &ret) {
        if (level>=n) {
            ret.push_back(ans);
            return;
        }
        bool shu,zuo,you;
        for (int i=0;i<n;i++) {
            // meiju mei hang
            shu=((1<<i) & f[0]) == 0;
            zuo=((1<<(n-1+i-level))&f[1])==0;
            you=((1<<(i+level))&f[2])==0;
            if (shu&&zuo&&you) {
                f[0]|=(1<<i);
                f[1]|=(1<<(n-1+i-level));
                f[2]|=(1<<(i+level));
                ans.push_back(i);
                DFS(n,level+1,f,ans,ret);
                ans.pop_back();
                f[0]&=~(1<<i);
                f[1]&=~(1<<(n-1+i-level));
                f[2]&=~(1<<(i+level));
            }
        } 
        return;    
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
    auto res = Solution().solveNQueens(4);
    for (auto i:res) {
        for (auto j:i)
            cout<<j<<endl;
        cout<<endl;
    }
    return 0;
}