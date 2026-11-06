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
    int ret =0;
    int kthSmallest(TreeNode* root, int k) {
        return inorderTraversal(root, k);
        
    }
    int inorderTraversal(TreeNode* root, int& k){
        if(root == nullptr) return -1;
        int ret = inorderTraversal(root->left,k);
        k--;
        if(k==0) ret = root->val;
        if(k<=0) return ret;
            
        return inorderTraversal(root->right,k);
    }
    
};
