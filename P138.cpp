#include <stdlib.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* copy = new Node(head->val);
        if (head->random) {
            Node *p = head->random;
            head->random = NULL;
            copy->random = copyRandomList(p);
        }
        if (copy->random)
        return copy;
    }
};