#include "header.h"

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            return f(root,1);                
        }
        int f(TreeNode* t, int l) {
            if (!t) return l-1;
            return max(f(t->left,l+1),f(t->right,l+1));
        }
        
};

int main() {
    cout << Solution().maxDepth(NULL);
    return 0;
}
