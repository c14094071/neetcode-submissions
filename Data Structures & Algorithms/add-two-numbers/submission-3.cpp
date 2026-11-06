/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* h = dummy;
        int carry=0;
        while(!(p==nullptr && q==nullptr)){
            int pval = p==nullptr?0:p->val;
            int qval = q==nullptr?0:q->val;
            int sum = pval+qval+carry;
            carry=0;
            if(sum>=10){
                sum-=10;
                carry = 1;
            }
            ListNode* newnode = new ListNode(sum);
            h->next = newnode;
            h = h->next;
            p= p==nullptr?p:p->next;
            q= q==nullptr?q:q->next;
        }
        if(carry==1){
            ListNode* newnode = new ListNode(1);
            h->next = newnode;
        }
        return dummy->next;
    }
};
