#include<vector>
#include<iostream>
#include<cstdlib>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m,n;
        m=board.size();
        if (m==0) return false;
        n=board[0].size();
        if (n==0) return false;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (word[0]==board[i][j]) {
                    char c=board[i][j];
                    board[i][j]= '0';
                    bool t=test(board,i,j,word,1);
                    board[i][j]=c;
                    if (t) return t;
                }
        return false;
    }
    bool test(vector<vector<char>> &b,int x,int y,const string &word,int l) {
        if (l>=word.length()) return true;
        if (b[x][y]!=word[l]) return false;
        char c=b[x][y];
        b[x][y]='0';
        int i,j,m,n;
        bool t;
        m=b.size();
        n=b[0].size();
        i=x+1;j=y;
        if (i<m) t=test(b,i,j,word,l+1);
        if (t) return t;

        i=x;j=y+1;
        if (j<n) t=test(b,i,j,word,l+1);
        if (t) return t;

        i=x-1;j=y;
        if (i>=0) t=test(b,i,j,word,l+1);
        if (t) return t;

        i=x;j=y-1;
        if (j>=0) t=test(b,i,j,word,l+1);
        if (t) return t;
        b[x][y]=c;
        return false;
    }
};


int main() {
    vector<vector<char>> b={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << Solution().exist(b,"ABCCED");
    return 0;
}
