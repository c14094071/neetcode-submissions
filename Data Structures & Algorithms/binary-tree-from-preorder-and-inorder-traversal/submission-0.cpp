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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(),inorder.end(),preorder[0]);
        int mid = std::distance(inorder.begin(),it);
        vector<int> preleft(preorder.begin()+1,preorder.begin()+1+mid);
        vector<int> preright(preorder.begin()+1+mid,preorder.end());
        vector<int> inleft(inorder.begin(),inorder.begin()+mid);
        vector<int> inright(inorder.begin()+mid+1,inorder.end());
        root->left = buildTree(preleft,inleft);
        root->right = buildTree(preright,inright);
        return root;

    }
};
