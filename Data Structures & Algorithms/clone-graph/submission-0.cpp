/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if( node ==nullptr) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* copy_original = new Node(node->val);
        mp[node] = copy_original;
        dfs(mp, node, copy_original);
        return copy_original;
    }
    void dfs(unordered_map<Node*, Node*>& mp, Node* node, Node* copy){

        if(node == nullptr) return;
        
        int n = node->neighbors.size();
        vector<Node*> copy_neighbors;
        copy->neighbors = copy_neighbors;
        for(int i=0; i<=n-1;i++){
            if(mp.count(node->neighbors[i])){
                copy->neighbors.push_back(mp[node->neighbors[i]]);
            }else{
                Node *copy_node = new Node(node->neighbors[i]->val);
                mp[node->neighbors[i]] = copy_node;
                copy->neighbors.push_back(copy_node);
                dfs(mp, node->neighbors[i],copy->neighbors[i]);
            }
            
        }
        copy->val = node->val;
    }
};
;