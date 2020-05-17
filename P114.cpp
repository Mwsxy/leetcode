#include "header.h"

class Solution {
    public:
        void flatten(TreeNode* root) {
            stack<TreeNode*> st;
            TreeNode *last = nullptr;
            st.push(root);
            while (!st.empty()) {
                TreeNode *p = st.top();
                st.pop();
                if (last) last->right = p;
                while (p) {
                    if (p->right) st.push(p->right);
                    if (p->left) {
                        p->right = p->left;
                        p->left = nullptr;
                        p = p->right;
                    }
                    else 
                    {
                        last = p;
                        break;
                    }
                }
            }
        }
};
