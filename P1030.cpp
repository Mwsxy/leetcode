#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        int fw[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
        int h,t;
        auto X=new int[R*C+10];
        auto Y=new int[R*C+10];
        bool f[100][100];
        for (int i=0;i<R;i++) for (int j=0;j<C;j++)
            f[i][j]=false;
        h=t=0;
        X[t]=r0;
        Y[t++]=c0;
        f[r0][c0]=true;
        ans.push_back({r0,c0});
        int x,y,xx,yy;
        while (h!=t) {
            x=X[h];
            y=Y[h];
            ++h;
            for (int i=0;i<4;i++) {
                xx=x+fw[i][0];
                yy=y+fw[i][1];
                if (xx>=0 && xx<R && yy>=0 && yy<C && f[xx][yy]!=true) {
                    f[xx][yy]=true;
                    ans.push_back({xx,yy});
                    X[t]=xx;
                    Y[t]=yy;
                    t++;
                }
            }
        }
        return ans;        
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