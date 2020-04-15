#include "header.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p,*pre;
        p = head;
        pre = nullptr;
        for (int i=1;i<m;i++) {
            pre = p;
            p=p->next;
        }
        ListNode *insertPre = pre;
        if (pre)
            pre=pre->next;
        else 
            pre=head;
        for (int i=m;i<n;i++) {
            p = delAfter(&head,pre);
            insertAfter(&head,insertPre,p);
        }
        return head;
    }
    ListNode* delAfter(ListNode **phead, ListNode *pre) {
        ListNode *p;
        if (!pre) {
            p = *phead;
            *phead = (*phead)->next;
            return p;
        }
        p = pre->next;
        pre->next = p->next;
        return p;
    }
    void insertAfter(ListNode **phead, ListNode *pre, ListNode *toInsert) {
        ListNode *p = pre;
        if (!pre) {
            // insert head
            toInsert->next=*phead;
            *phead = toInsert;
            return;
        }
        toInsert->next = pre->next;
        pre->next=toInsert;
        return;
    }
};