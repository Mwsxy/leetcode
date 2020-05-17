#include "header.h"

class Solution {
    public:
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            if (!root) return {};
            if (root->val == sum && !root->left && !root->right)
                return {{root->val}};
            vector<vector<int>> ret_c[2], ret_r, ret;
            ret_c[0] = pathSum(root->left, sum - root->val);
            ret_c[1] = pathSum(root->right, sum - root->val);
            for (int i=0;i<2;i++)
                for (auto t : ret_c[i]) {
                    vector<int> tmp = t;
                    if (!t.empty()) {
                        tmp.insert(tmp.begin(), root->val);
                        ret.push_back(tmp);
                    }
                }
            return ret;
        }
};


