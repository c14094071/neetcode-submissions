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
            deque<TreeNode*> temp;
            
            while(!bfs.empty()){
                TreeNode* tp = bfs.front();
                if(bfs.size()==1){
                    vec.push_back(tp->val);
                }
                if(tp->left) temp.push_back(tp->left);
                if(tp->right) temp.push_back(tp->right);
                bfs.pop_front();
            }
            bfs = temp;

        }
        return vec;
    }
};
