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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* curr,* prev;
        if((head->next)!=nullptr){
            curr= head->next;
            prev = head;
            prev->next = nullptr; //for linkedlist end
        }else return head;
        ListNode* next_curr;
        while((curr->next) !=nullptr){
            next_curr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_curr;

        }
        curr->next= prev;
        return curr;

    }
};
