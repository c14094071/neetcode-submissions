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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        deque<TreeNode*> dfs; //順序問題而不用stack
        vector<vector<int>> vec;
        if(root ==nullptr) return vec;
        dfs.push_back(root);
        while(!dfs.empty()){
            deque<TreeNode*> temp;
            vector<int> vec1;
            while(!dfs.empty()){
                TreeNode* tp = dfs.front();
                vec1.push_back(tp->val);
                if(tp->left) temp.push_back(tp->left);
                if(tp->right) temp.push_back(tp->right);
                dfs.pop_front();
            }
            vec.push_back(vec1);
            dfs = temp;

        }
        return vec;
        
    }
    
};
