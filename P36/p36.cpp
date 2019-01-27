#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int heng[9],shu[9],kuai[9];
        for (int i=0;i<9;i++)
            heng[i]=shu[i]=kuai[i]=0;
        int n,h,s,k,t;
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++) {
                if (board[i][j]=='.') continue;
                n=board[i][j]-'0';
                h=i;s=j;
                k=i/3*3+j/3;
                t=1<<n;
                if ((t&heng[h] || t&shu[s] || t&kuai[k]) == true) return false;
                else {
                    heng[h]|=t;
                    shu[s]|=t;
                    kuai[k]|=t;
                }
            }
        return true;
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
    auto res = Solution().xxx;
    cout << res <<endl;
    return 0;
}