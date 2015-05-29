//Note 1. while(p1||p2||carry)
//Note 2. p1?p1->val:0
//Note 3. int carry=0;
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
        ListNode *p1 = l1, *p2 = l2, *head = NULL, *p;
        int carry=0;
        while(p1||p2||carry)
        {
            int d1 = p1?p1->val:0;
            int d2 = p2?p2->val:0;
            carry+=d1+d2;
            if(head == NULL)
                p = head = new ListNode(carry%10);
            else
            {
                p->next = new ListNode(carry%10);
                p = p->next;
            }
            carry /= 10;
            if(p1)
                p1=p1->next;
            if(p2)
                p2=p2->next;
        }
        return head;
    }
};
