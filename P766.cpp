#include "header.h"

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return true;
        if (matrix.front().empty()) return true;
        int m,n;
        m = matrix.size();
        n = matrix.front().size();
        bool ok = true;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int _i, _j;
                _i = i+1; _j =j+1;
                if (_i>=m || _j >=n) break;
                if (matrix[i][j]!=matrix[_i][_j]) {
                    ok = false;
                    goto check;
                }
            }
        }
        check:return ok;
    }
};

int main() {
    return 0;
}