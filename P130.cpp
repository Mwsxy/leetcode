#include "header.h"
#include <functional>
#include <vector>

class Solution {
public:
    int top,bot,left,right;
    inline bool inside(int x, int y) {
        if (x>=top && x<=bot && y>=left && y<=right) return true;
        return false;
    }
    inline bool onEdge(int x, int y) {
        if (x==top || x==bot || y==left || y==right) return true;
        return false;
    }
    int *s;
    int findx(int x) {
        if (s[x]!=x) {
            if (s[x]<0) return x;
            else s[x] = findx(s[x]);
        }
        return s[x];
    }
    void solve(vector<vector<char>>& board) {
        int r,c;
        r = board.size();
        if (r==0) return;
        c = board[0].size();
        if (c==0) return;
        top = left = 0;
        bot = r-1;
        right = c-1;
        s = new int[r*c];
        for (int i=0; i<r*c; i++) s[i] = i;
        for (int i=0; i<r; i++) 
            for (int j=0; j<c; j++) {
                if (board[i][j] == 'X') continue;
                int x,y;
                x = i+1; y = j;
                if (inside(x, y) && board[x][y]=='O') {
                    s[findx(i*c+j)]=s[findx(x*c+y)];
                }
                x = i; y = j+1;
                if (inside(x, y) && board[x][y]=='O') {
                    s[findx(i*c+j)]=s[findx(x*c+y)];
                }
            }
        for (int i=0; i<r; i++) {
            if (board[i][left]=='O') s[findx(i*c+left)] = -1;
            if (board[i][right] == 'O') s[findx(i*c+right)] = -1;
        }
        for (int j=0; j<c; j++) {
            if (board[top][j] == 'O') s[findx(top*c+j)] = -1;
            if (board[bot][j] == 'O') s[findx(bot*c+j)] = -1;
        }
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++) {
                int t = i*c+j;
                if (s[findx(t)]!=-1) board[i][j]='X';
            }
        
    }
};

int main() {
    vector<vector<char>> m = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution().solve(m);
    for (auto &line:m) {
        for (auto &c:line)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}