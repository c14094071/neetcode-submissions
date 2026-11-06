/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> bfs;
        vector<int> vec;
        if(root == nullptr) return vec;
        bfs.push_back(root);
        while(!bfs.empty()){
            TreeNode* tp = nullptr;
            int qSize = bfs.size();
            for(int i=0;i<qSize;i++){
                tp = bfs.front();
                
                if(tp->left) bfs.push_back(tp->left);
                if(tp->right) bfs.push_back(tp->right);
                bfs.pop_front();
            }
            if(tp!=nullptr) vec.push_back(tp->val);

        }
        return vec;
    }
};
