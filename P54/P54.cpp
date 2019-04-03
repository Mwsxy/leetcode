#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int top,bottom,left,right;
        top=0;
        bottom=matrix.size()-1;
        if (bottom<0) return ret;
        left=0;
        right=matrix[0].size()-1;
        if (right<0) return ret;

        vector<vector<int>> towards={{0,1},{1,0},{0,-1},{-1,0}};
        int f=0,n=(bottom+1)*(right+1);
        int x=0,y=0;
        int s;
        while (n>0) {
            ret.push_back(matrix[x][y]);
            n--;
            x+=towards[f][0];
            y+=towards[f][1];
            s=checkState(x,y,top,bottom,left,right);
            switch (s)
            {
                case 0:
                    break;
                case 1:
                    left++;
                    x++;
                    y++;
                    break;
                case 2:
                    top++;
                    x++;
                    y--;
                    break;
                case 3:
                    right--;
                    x--;
                    y--;
                    break;
                case 4:
                    bottom--;
                    x--;
                    y++;
                default:
                    break;
            }
            if (s!=0) f++;
            if (f>=4) f=0;
        }
        return ret;
    }
private:
    int checkState(int x,int y,int t,int b,int l, int r) {
//         1     
//      4  0  2
//         3
//         
        int s;
        if (x<t) return 1;
        if (x>b) return 3;
        if (y<l) return 4;
        if (y>r) return 2;
        return 0;
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
    vector<vector<int>> a={
        {}
    };
    auto res = Solution().spiralOrder(a);
    for (auto i:res)
        cout << i <<" ";
    cout<<endl;
    return 0;
}