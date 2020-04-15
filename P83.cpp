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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p;
		p=head;
		while (p!=nullptr) {
			if (p->next!=nullptr && p->val==p->next->val) 
				p->next=p->next->next;
			else 
				p=p->next;
		}
		return head;
    }
};