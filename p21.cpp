#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1,*p2;
        ListNode *prev,*curr;
        ListNode *fakeHead = new ListNode(0);
        p1=l1;
        p2=l2;
        prev=fakeHead;
        bool Out=false;
        while (p1!=nullptr || p2!=nullptr) {
            if (p1==nullptr) {
                curr=p2;
                p2=p2->next;
                Out=true;
            } 
            else if (p2==nullptr) {
                curr=p1;
                p1=p1->next;
                Out=true;
            } 
            else if (p1->val<p2->val) {
                curr=p1;
                p1=p1->next;
            }
            else {
                curr=p2;
                p2=p2->next;
            }
            prev->next=curr;
            prev=curr;
        }
        curr=fakeHead->next;
        delete fakeHead;
        return curr;
    }
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


int main() {
    ListNode *p;
    ListNode *l1=new ListNode(1);
    p=l1;
    p->next=new ListNode(2);p=p->next;
    p->next=new ListNode(4);p=p->next;
    ListNode *l2=new ListNode(1);
    p=l2;
    p->next=new ListNode(3);p=p->next;
    p->next=new ListNode(4);p=p->next;

    auto res = Solution().mergeTwoLists(l1,l2);
    while (res!=nullptr) {
        cout<<res->val<<" ";
        res=res->next;
    }
    
    return 0;
}