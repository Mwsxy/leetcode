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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode fakeHead(0);
        ListNode *h,*p,*q,*reserve;
        h=&fakeHead;
        h->next=head;
        int i;
        do {
            i=0;
            for (reserve=h->next;reserve!=nullptr && i<k;i++,reserve=reserve->next);
            if (i<k && reserve==nullptr) break;
            p=h;
            while (p->next!=reserve) {
                //p -> q -> t
                //delete p->next then insert it to h->next
                if (p==h) {
                    p=p->next;
                    continue;
                }
                q=p->next;
                p->next=p->next->next;
                q->next=h->next;
                h->next=q;
            }
            h=p;
            if (h->next!=reserve) cout << "ERROR!";
        } while (reserve!=nullptr);
        return fakeHead.next;
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
    ListNode *head = new ListNode(1),*p;
    p=head;
    p->next = new ListNode(2);p=p->next;
    p->next = new ListNode(3);p=p->next;
    p->next = new ListNode(4);p=p->next;
    p->next = new ListNode(5);
    auto res = Solution().reverseKGroup(head,2);
    while (res!=nullptr) {
        cout << res->val <<endl;
        res=res->next;
    }
    
    return 0;
}