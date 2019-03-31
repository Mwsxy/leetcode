#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        unsigned long flag[3];
        int nums=0;
        flag[0]=flag[1]=flag[2]=0;
        DFS(n,0,flag,nums);
        return nums;
    }
private:
    void DFS(int n,int level,unsigned long f[3],int &nums) {
        if (level>=n) {
            ++nums;
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
                DFS(n,level+1,f,nums);
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
    auto res = Solution().totalNQueens(5);
    cout << res <<endl;
    return 0;
}