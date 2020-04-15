#include "header.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        long long vval = root->val;
        // basic
        if (root->left && root->left->val >= vval)
            return false;
        if (root->right && root->right->val <= vval) 
            return false;
        bool ok1,ok2;
        if (vval >= lt || vval <= bt)
            return false;
        long long tmp;
        tmp = lt;
        lt = min(vval,lt);
        ok1 = isValidBST(root->left);
        lt = tmp;
        if (!ok1) return false;
        
        tmp = bt;
        bt = max(vval,bt);
        ok2 = isValidBST(root->right);
        bt = tmp;
        if (!ok2) return false;
        return true;
    }
    long long lt=INT64_MAX,bt=INT64_MIN;
};

int main() {
    auto p = new TreeNode(2);
    p->left = new TreeNode(1);
    p->right= new TreeNode(3);
    cout << Solution().isValidBST(p);
    return 0;
}