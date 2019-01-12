#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head = new ListNode(0); //fake head
        auto p1 = l1;
        auto p2 = l2;
        auto pos = head;
        int addAnswer,extension=0;
        auto tmp=pos;
        bool goOut=false;
        while (p1!=nullptr || p2 != nullptr) {
            if (p1==nullptr) {
                addAnswer=p2->val+extension;
                extension=addAnswer/10;
                tmp=p2;
                
                tmp->next=p2->next;
                p2=p2->next;
                if (extension==0) goOut=true;
            }
            else if (p2==nullptr) {
                addAnswer=p1->val+extension;
                extension=addAnswer/10;
                tmp=p1;
                tmp->next=p1->next;
                p1=p1->next;
                if (extension==0) goOut=true;
            }
            else 
            {
                addAnswer=p1->val+p2->val+extension;
                extension=addAnswer/10;
                tmp=p1;
                p1=p1->next;
                p2=p2->next;
            }            
            tmp->val=addAnswer%10;
            pos->next=tmp;
            pos=tmp;        
            if (goOut) break;   
        }
        if (extension!=0) pos->next=new ListNode(extension);

        return head->next;
    }
};

int main() {
    auto l1=new ListNode(3);
    l1->next=new ListNode(7);
    // l1->next->next=new ListNode(5);
    auto l2=new ListNode(0);
    auto l3=Solution().addTwoNumbers(l2,l1);
    for (auto v=l3;v!=nullptr;v=v->next)
        cout<<v->val<<" ";
    return 0;
}