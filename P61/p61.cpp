#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      int i,j,n;
      ListNode *p,*q;
      p=head;
      i=0;
      while (p!=nullptr) {
        q=p;
        p=p->next;
        i++;
      }
      n=i;
      if (n==0) return nullptr;
      if (n==1) return head;
      k=k%n;
      p=head;
      for (i=0;i<n-k-1;i++) {
        p=p->next;
      }
      q->next=head;
      q=p->next;
      p->next=nullptr;
      return q;
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
 
  ListNode *head=new ListNode(0);
  ListNode *p=head;
  p->next=new ListNode(1);p=p->next;
  p->next=new ListNode(2);p=p->next;
  p->next=new ListNode(3);p=p->next;
  p->next=new ListNode(4);p=p->next;
  p->next=new ListNode(5);p=p->next;
  p->next=new ListNode(6);p=p->next;
  auto res = Solution().rotateRight(head,3);
    while (res!=nullptr) {
      cout << res->val <<endl;
      res=res->next;
    }
    cout << "finished" << endl;
                               
    return 0;
}
