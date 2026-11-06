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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int len = lists.size();
        while(len>1){
            int half = (len-1)/2;
            for(int i=0;i<=half;i++){
                lists[i] = mergeLists(lists[i],lists[len-i-1]);
            }
            
            len = half+1;
        }
        return lists[0];
    }
    ListNode* mergeLists(ListNode* n1, ListNode* n2){
        if(n1 == n2) return n1;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(n1 && n2){
            if(n1->val <= n2->val){
                tail->next = n1;
                n1 = n1->next;
                tail = tail->next;
            }else{
                tail->next = n2;
                n2 = n2->next;
                tail = tail->next;
            }
        }
        //剩下的(其中一方較多)
        if(n1) tail->next = n1;
        if(n2) tail->next = n2;
        dummy = dummy->next;

        return dummy;
    }
};
