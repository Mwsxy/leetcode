#include "header.h"
class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (!root) return true;
            return isSymmetric(root->left, root->right);
                
        }
        bool isSymmetric(TreeNode* p, TreeNode* q) {
            if (p && q)
                if (p->val == q->val)
                    return isSymmetric(p->left , q->right) && isSymmetric(p->right , q->left);
                else 
                    return false;
            else 
                if (!p && !q)
                    return true;
            return false;
        }
};

int main() {
    TreeNode* root=NULL;
    cout << Solution().isSymmetric(root);
    return 0;
}
