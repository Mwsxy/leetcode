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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*q;
        p=q=head;
        for (auto i=0;i<n;i++)
            p=p->next;
        // now, p is n-1 after q
        if (p==nullptr) {
            //this situation will delete the head
            head=head->next;
            delete q;
            return head;
        }
        //now don't care if q is the head
        while (p->next!=nullptr) {
            p=p->next;
            q=q->next;
        }
        //q->next will be delete
        p=q->next;
        q->next=p->next;
        delete p;
        return head;
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
    ListNode *head = new ListNode(1);
    ListNode *p;
    p = head;
    p->next = new ListNode(2); p=p->next;
    p->next = new ListNode(3); p=p->next;
    p->next = new ListNode(4); p=p->next;
    p->next = new ListNode(5); p=p->next;
    auto res = Solution().removeNthFromEnd(head,5);
    while (res!=nullptr) {
        cout << res->val <<endl;
        res=res->next;
    }
    return 0;
}