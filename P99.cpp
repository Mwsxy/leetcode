#include "header.h"

class Solution {
public:
    void recoverTree(TreeNode* root) {
        w1(root);
        w2(root);
    }
    void w1(TreeNode* root) {
        if (!root) return;
        if (root->left) w1(root->left);
        if (prev)
            if (prev->val>root->val) {
                swap(prev->val,root->val);
                s1 = true;
            }
            else if (s1)
                return;
        prev = root;
        if (root->right) w1(root->right);        
    }
    void w2(TreeNode* root) {
        if (!root) return;
        if (root->right) w2(root->right);       
        if (next)
            if (next->val<root->val) {
                swap(next->val,root->val);
                s2 = true;
            }
            else if (s2)
                return;
        next = root;
        if (root->left) w2(root->left);
    }
    TreeNode *prev = nullptr, *next = nullptr;
    bool s1=false, s2=false;
};

int main() {
    return 0;
}