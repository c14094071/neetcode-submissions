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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = p->val < q->val ? p->val:q->val;
        int high = p->val < q->val ? q->val:p->val;
        
        while(root){
            if(root->val<low && root->val <high){
                root = root->right;
            }else if(root->val >low && root->val >high){
                root = root->left;
            }else{
                return root;
            }
        }
        
        return nullptr;
    }
};
