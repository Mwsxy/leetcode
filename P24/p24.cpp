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
    ListNode* swapPairs(ListNode* head) {
        ListNode fakeHead(0);
        ListNode *p,*q,*h;
        h=&fakeHead;
        h->next=head;
        p=h;
        while (p->next!=nullptr && p->next->next!=nullptr) {
            /* p  q  q->next(r) */
            q=p->next;
            p->next=q->next;
            q->next=q->next->next;
            p->next->next=q;
            p=p->next->next;
        }
        return h->next;
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
    auto res = Solution().swapPairs(nullptr);
    cout << res <<endl;
    return 0;
}