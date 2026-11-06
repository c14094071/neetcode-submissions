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
    ListNode* reverseKGroup(ListNode* head, int k) {
        deque<ListNode*> stk;
        ListNode* tail = head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* dummy2 = dummy;
        int count =0;
        while(tail){
            stk.push_back(tail);
            tail = tail->next;
            
            if(stk.size()==k){
                while(!stk.empty()){
                    
                    ListNode* tp = stk.back();
                    dummy->next = tp;
                    stk.pop_back();
                    dummy = dummy->next;
                    //cout<<dummy->val<<endl;
                    
                }
                dummy->next = nullptr;
                
            }
            
        }
        if(stk.size()>0){
            while(!stk.empty()){
                
                dummy->next = stk.front();
                dummy = dummy->next;
                stk.pop_front();
            }
        }
        return dummy2->next;
    }
};
