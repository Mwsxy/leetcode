#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool testSudoku(vector<vector<char>> &board,
                    int x,
                    int heng[],
                    int shu[],
                    int kuai[]) {
        if (x>=81) 
            return true;
        int n,h,k,s,t,i,j;
        bool Out=false;
        for (int xx=x/9;xx<81;xx++) {
            i=xx/9;
            j=xx%9;
            if (board[i][j]!='.') continue;
            h=i;s=j;
            k=i/3*3+j/3;
            t=heng[h]|shu[s]|kuai[k];
            for (n=1;n<=9;n++) {
                if (((1<<n) & t)!=0) continue;
                heng[h]|=1<<n;
                shu[s]|=1<<n;
                kuai[k]|=1<<n;

                board[i][j]='0'+n;

                Out = testSudoku(board,xx+1,heng,shu,kuai);
                if (Out) return true;
                board[i][j]='.';
                heng[h]&=~(1<<n);
                shu[s]&=~(1<<n);
                kuai[k]&=~(1<<n);
            }
            return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
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

                heng[h]|=t;
                shu[s]|=t;
                kuai[k]|=t;

            }
        testSudoku(board,0,heng,shu,kuai);
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
    vector<vector<char>> board = {
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution().solveSudoku(board);
    for (auto i:board) {
        for (auto v:i) 
            cout << v << " ";
        cout<<endl;
    }
    return 0;
}
