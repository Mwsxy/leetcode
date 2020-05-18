#include <cstdint>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<stack>
#include<queue>
#include<map>
#include<climits>
using namespace std;

struct TreeNode {
public:

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    void preorder(TreeNode *t) {
            if (!t) return;
            cout<< t->val << " ";
            preorder(t->left);
            preorder(t->right);
    }
    void inorder(TreeNode *t) {
            if (!t) return;
            inorder(t->left);
            cout<< t->val << " ";
            inorder(t->right);
    }
    void print_order() {
        cout << "preorder: ";
        preorder(this);
        cout << endl;
        cout << "inorder: ";
        inorder(this);
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
