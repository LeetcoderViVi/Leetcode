//Node:
/**
head is NULL?
head->val = val?
head->next = NULL?
*/
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
    ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL)
      return head;
    ListNode* p = head;
		while(p)
		{
			if(head->val == val)
				head = head->next;
			if(p->next!=NULL&&p->next->val==val)
				p->next = p->next->next;
			else
				p = p->next;
		}
		return head;
    }
};
