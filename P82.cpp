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
        ListNode* p, *prev = nullptr;
		if (head==nullptr || head->next==nullptr) return head;
		auto v=head->val;

		prev = nullptr;
		p = head;
		while (p!=nullptr) {
			if (p->next!=nullptr && p->val==p->next->val) {
				v = p->val;
				while (p!=nullptr && p->val==v) {
					if (prev!=nullptr) {
						prev->next=p->next;
						free(p);
						p=p->next;
					}
					else {
						head=head->next;
						free(p);
						p=head;
					}
				}
			}
			else {
				prev=p;
				p=p->next;
			}	
		}
		return head;
    }

};