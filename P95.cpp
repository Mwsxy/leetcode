#include "header.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> r;
        if (n<=0) return r;
        return gen(n,0);
    }

    vector<TreeNode*> gen(int n,int offset) {
        vector<TreeNode *> ret;
        if (n<=0) {
            ret.push_back(nullptr);
            return ret;
        }
        if (n==1) {
           ret.push_back(new TreeNode(offset+1));
           return ret;
        }   
        for (int i=0;i<n;++i) {
            auto lef = gen(i,offset);
            auto rig = gen(n-i-1,offset+i+1);
            for (auto u:lef)
                for (auto v:rig) {
                    auto mid = new TreeNode(offset+i+1);
                    mid->left = u;
                    mid->right = v;
                    ret.push_back(mid);
                }
        }
        return ret;
    }
};

void ShowTree(TreeNode *t) {
    queue<TreeNode*> q;
    
    q.push(t);
    while (!q.empty()) {
        auto p = q.front();
        
        if (p)
            cout <<p->val<<" ";
        else 
            cout << "null" << " ";
        q.pop();
        if (p) {
            if (p->left || p->right) {
                q.push(p->left);
                q.push(p->right);
            }
        }        
    }
    cout <<endl;
    return;
}

int main() {
    auto ans = Solution().generateTrees(3);
    for (auto v:ans) {
        ShowTree(v);
        cout << endl;
    }
}