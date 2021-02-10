#include <array>
#include <cstdint>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstddef>
#include<stack>
#include<queue>
#include<map>
#include<climits>
#include<cmath>
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

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

template<typename T>
void print(vector<T> a) {
    for (const auto &v:a)
        cout << v << " ";
    cout << endl;
    return;
}
