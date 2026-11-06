/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> umap;
        for(auto cur = head; cur!=nullptr;cur=cur->next){
            Node* newnode = new Node(cur->val);
            umap[cur] = newnode;
        }
        for(auto cur = head; cur!=nullptr;cur=cur->next){
            umap[cur]->next = umap[cur->next];
            umap[cur]->random = umap[cur->random];
        }
        return umap[head];
        
    }
};
