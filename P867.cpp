#include "header.h"
#include <vector>

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows,cols;
        if (matrix.empty()) return {};
        rows = matrix.size();
        cols = matrix.front().size();
        vector<vector<int>> ret;
        ret.resize(cols);
        for (auto &c:ret) c.resize(rows);
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                ret[j][i] = matrix[i][j];
            }
        }
        return ret;;
    }  
};

int main() {
    return 0;
}