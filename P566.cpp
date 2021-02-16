#include "header.h"
#include <vector>

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int _r, _c;
        _r = nums.size();
        if (nums.empty()) return nums;
        if (nums.front().empty()) return nums;
        _c = nums.front().size();
        if (_r *_c != r*c) return nums;
        vector<vector<int>> ret;
        ret.resize(r);
        for (auto &row:ret) row.resize(c);
        for (int i=0; i<_r; i++) {
            for (int j=0; j<_c; j++) {
                int _i,_j;
                _i = (i*_c+j)/c;
                _j = (i*_c+j)%c;
                ret[_i][_j] = nums[i][j];
            }
        }
        return ret;
    }
};


int main() {
    return 0;
}