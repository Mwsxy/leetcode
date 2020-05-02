#include "header.h"

class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty()) return nullptr;
            int root_val;
            int pos = -1;
            for (size_t j=0; j<preorder.size(); ++j) {
                for (size_t i=0; i<inorder.size(); ++i) {
                    if (preorder[j] == inorder[i]) {
                        pos = i;
                        root_val = preorder[j];
                        break;
                    }
                }
                if (pos!=-1) break;
            }
            if (pos==-1) return nullptr;
            vector<int> pre(preorder.begin()+1,preorder.end());
            vector<int> in1(inorder.begin(),inorder.begin()+pos);
            vector<int> in2(inorder.begin()+pos+1,inorder.end());
            TreeNode* root = new TreeNode(root_val);
            root->left = buildTree(pre,in1);
            root->right = buildTree(pre,in2);
            return root;
        }
        
};
void show(TreeNode *t)
{
    if (!t) return;
    cout << t->val << " ";
    show(t->left);
    show(t->right);
}

int main() {
    vector<int> preorder = {3,9,20,15,7},
                inorder =  {9,3,15,20,7};
    TreeNode *root = Solution().buildTree(preorder,inorder);
    show(root);
    return 0;
}
