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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        int len=0;
        for(auto p = dummy;p->next!=nullptr;p=p->next,len++){}
        int rem = len-n;
        ListNode* p = dummy;

        
        while(rem>0){//前一個
            p = p->next;
            rem--;
        }
        
        if(p->next!=nullptr){
            cout<<p->val;
            ListNode* dele = p->next;
            p->next = dele->next;

        }
        dummy = dummy->next;
        return dummy;


    }
};
