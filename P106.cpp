#include "header.h"

class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if (postorder.empty() || inorder.empty()) return nullptr;
            int root_val;
            int pos = -1;
            int pos_p = -1;
            for (size_t j=postorder.size()-1; j>=0; --j) {
                for (size_t i=0; i<inorder.size(); ++i) {
                    if (postorder[j] == inorder[i]) {
                        pos = i;
                        pos_p = j;
                        root_val = postorder[j];
                        break;
                    }
                }
                if (pos!=-1) break;
            }
            if (pos==-1) return nullptr;
            vector<int> post(postorder.begin(),postorder.begin()+pos_p);
            vector<int> in1(inorder.begin(),inorder.begin()+pos);
            vector<int> in2(inorder.begin()+pos+1,inorder.end());
            TreeNode* root = new TreeNode(root_val);
            root->left = buildTree(in1,post);
            root->right = buildTree(in2,post);
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
    vector<int> postorder = {9,15,7,20,3},
                inorder =  {9,3,15,20,7};
    TreeNode *root = Solution().buildTree(inorder,postorder);
    show(root);
    return 0;
}
