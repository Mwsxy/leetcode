/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<algorithm>
#include<cstdlib>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lit,*big;
        ListNode *p,*plit,*pbig;
        lit=big=nullptr;
        p=head;
        while (p!=nullptr) {
            if (p->val<x) {
                if (lit==nullptr) {
                    lit=p;
                    p=p->next;
                    lit->next=nullptr;
                    plit=lit;
                }
                else {
                    plit->next=p;
                    p=p->next;
                    plit=plit->next;
                    plit->next=nullptr;
                }
            }
            else {
                if (big==nullptr) {
                    big=p;
                    p=p->next;
                    big->next=nullptr;
                    pbig=big;
                }
                else {
                    pbig->next=p;
                    p=p->next;
                    pbig=pbig->next;
                    pbig->next=nullptr;
                }
            }
        }
        
        if (lit!=nullptr && big!=nullptr) plit->next=big;
        else if (lit!=nullptr) return lit;
        else if (big!=nullptr) return big;
        else return nullptr;
        return lit;
    }
};