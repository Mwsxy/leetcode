#include "header.h"
#include <cstddef>

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n=0;
        ListNode* p = head;
        while (p) {
            n++;
            p=p->next;
        }
        TreeNode *root = makeTree(n);
        inOrderSet(root,head);
        return root;
    }
    void inOrderSet(TreeNode *t,ListNode* &p) {
        if (!t) return;
        inOrderSet(t->left,p);
        t->val = p->val;
        p = p->next;
        inOrderSet(t->right,p);
    }
    TreeNode * makeTree(int n) {
        if (n==0) return nullptr;
        TreeNode **table = new TreeNode*[n];
        for (int i=0;i<n;i++) {
            table[i]  = new TreeNode(0);
            if (i>0) {
                int f = ((i+1)>>1)-1;
                if ((i+1) % 2 ==0)
                    table[f]->left = table[i];
                else 
                    table[f]->right = table[i];
            }
        }
        TreeNode *root = table[0];
        delete[] table;
        return root;
    }

};

void testTree(TreeNode *t) {
    if (!t) return;
    testTree(t->left);
    cout<<t->val<<" ";
    testTree(t->right);
}

int main(int argc, const char *argv[]) {

    ListNode * p = new ListNode(1);
    ListNode * r = p;
    p->next = new ListNode(2); p=p->next;
    p->next = new ListNode(3); p=p->next;
    p->next = new ListNode(4); p=p->next;
    p->next = new ListNode(5); p=p->next;
    auto k = Solution().sortedListToBST(r);
    testTree(k);

    return 0;
}
