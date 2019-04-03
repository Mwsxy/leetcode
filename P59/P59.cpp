#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        vector<int> t;
        for (int i=0;i<n;i++) {
            t=vector<int>();
            for (int j=0;j<n;j++)
                t.push_back(getNumber(i,j,n));
            ret.push_back(t);
        }
        return ret;
    }
private:
    int getNumber(int x,int y, int n) {
        int c,cx,cy;
        cx=min(x,n-1-x);
        cy=min(y,n-1-y);
        c=min(cx,cy);
        cx=x-c;
        cy=y-c;
        int k=n-2*c;
        int p=0;
        for (int i=n;i>k;i=i-2)
            p+=4*(i-1);
        if (cx==0) {
            return p+cy+1;
        }
        else if (cx==k-1) {
            return p+2*(k-1)+k-1-cy+1;
        }
        else if (cy==0) {
            return p+3*(k-1)+k-1-cx+1;
        }
        else if (cy==k-1) {
            return p+(k-1)+cx+1;
        }
        //can not run this
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
    auto res = Solution().generateMatrix(10);
    for (auto v:res) {
        for (auto x:v)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}