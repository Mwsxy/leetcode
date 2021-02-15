#include "header.h"

class Solution {
public:
    int ans;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* t, long p) {
        if (!t) {
            ans += p;
            return;
        }
        int n = p*10+t->val;
        if (t->left) dfs(t->left, n);
        if (t->right) dfs(t->right, n);
        if (!t->left && !t->right) {
            ans += n;
        }
    }
};

int main() {



    return 0;
}