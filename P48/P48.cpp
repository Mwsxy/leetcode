#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n;
        int i,j;
        n=matrix.size();
        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        for (i=0;i<n;i++)
            for (j=0;j<n/2;j++)
                swap(matrix[i][j],matrix[i][n-1-j]);
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
    vector<vector<int>> m={
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}};
    Solution().rotate(m);
    for (auto i:m) {
        for (auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;   
}