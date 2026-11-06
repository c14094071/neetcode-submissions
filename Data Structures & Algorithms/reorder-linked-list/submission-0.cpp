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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int n=1;
        for(auto p =head;p->next!=nullptr;p=p->next) n++;
        int half = (n+1)/2;//取右邊
        int i=0;
        
        for(auto p =head;i<n;p=p->next,i++){
            if(i>=half){
                cout<<p->val<<endl;
                st.push(p);
                
            }
        }
        i=0;
        for(auto p =head;!st.empty()&&p->next!=nullptr ;p=p->next,i++){
            ListNode* temp = p->next;
            cout<<temp->val<<endl;
            p->next = st.top();
            st.pop();
            p = p->next;
            cout<<p->val<<endl;
            p->next = temp;
            if(st.empty()){
                p = p->next;
                p->next=nullptr;
                break;
            }
        }
      
    }
    
};
