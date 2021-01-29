/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* last;
    void set_last(Node* p) {last=p;}
    void con_last(Node* p) {
        if (last==NULL) {
            last = p;
            return;
        }
        last->next = p; 
        last = p;
    }

    Node* connect(Node* root) {
        Node* p;
        p = root;
        while (p!=NULL) {
            Node* l1 = p;
            if (l1->left) {
                set_last(NULL);
                while (l1!=NULL) {
                    con_last(l1->left);
                    con_last(l1->right);
                    l1 = l1->next;
                }
                p = p->left;
            }
            else break;    
        }
        return root;
    }
};

