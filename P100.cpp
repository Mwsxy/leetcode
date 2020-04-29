#include "header.h"
class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p && q)
                if (p->val==q->val)
                    return isSameTree(p->left, q->left) && isSameTree(p->right , q->right);
                else 
                    return false;
            else
                if (!p && !q)
                    return true;
                else 
                    return false;
        }
        
};

int main() {
    TreeNode p(1),q(0);
    cout << Solution().isSameTree(&p,&q);
    return 0;
}
