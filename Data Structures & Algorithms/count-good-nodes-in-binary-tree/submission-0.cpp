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
    int count=0;
    int goodNodes(TreeNode* root) {
        if(root ==nullptr) return 0;
        int max = root->val;
        dfs(root,max);
        return count;
    }
    TreeNode* dfs(TreeNode* root,int max){
        if(root==nullptr) return nullptr;
        if(root->val >= max){
            count++;
            max = root->val;
        }
        dfs(root->left,max);
        dfs(root->right,max);
        return nullptr;
    }
};
