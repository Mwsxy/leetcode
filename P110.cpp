class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return height(root)>=0;
    }
    int height(TreeNode* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        if (l<0 || r<0 || abs(l-r)>1.0) return -1;
        return max(l,r)+1;
    }
};
