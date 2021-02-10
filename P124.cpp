#include "header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int h1,h2,h;
        h = root->val;
        if (root->left) {
            h1 = dfs(root->left);
            ans = max(ans, h1);
            ans = max(ans, h1+root->val);
            h = max(h, root->val+h1);
        }
        if (root->right) {
            h2 = dfs(root->right);
            ans = max(ans, h2);
            ans = max(ans, h2+root->val);
            h = max(h, root->val+h2);
        }
        if (root->right && root->left) {
            ans = max(ans, h1+h2+root->val);
            // h = max(h, h1+h2+root->val);
        }
        return h;
    }
    int maxPathSum(TreeNode* root) {
        int h;
        ans = root->val;
        h = dfs(root);
        return max(ans, h);
    }
};
int main() {


    return 0;
}