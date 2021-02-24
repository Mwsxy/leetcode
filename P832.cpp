#include "header.h"
#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &line:A){
            reverse(line.begin(), line.end());
            for_each(line.begin(), line.end(), [](int &p){p^=1;});
        }
        return A;
    }
};

int main() {
    vector<vector<int>> a;
    a = {{1,1,0},{1,0,1},{0,0,0}};
    auto ret = Solution().flipAndInvertImage(a);
    for (auto l:ret) {
        for (auto p:l) {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}