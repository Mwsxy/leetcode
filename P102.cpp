#include "header.h" 

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res={};
            if (!root) return res;
            vector<TreeNode*> que;
            que.push_back(root);
            while (!que.empty()) {
                vector<int> ans;
                vector<TreeNode*> next;
                for (size_t i=0;i<que.size();++i) {
                    ans.push_back(que[i]->val);
                    if (que[i]->left) next.push_back(que[i]->left);
                    if (que[i]->right) next.push_back(que[i]->right);
                }
                res.push_back(ans);
                que=next;
            }
            return res;
        }
};

int main() {
    TreeNode* root = new TreeNode(0);
    auto res = Solution().levelOrder(root);
    for (auto l:res) {
        cout << endl;
        for (auto ele:l)
            cout << ele << " ";

    }
    return 0;
}
