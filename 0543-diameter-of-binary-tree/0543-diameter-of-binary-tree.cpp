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
    int maxi = 0;
    int size(TreeNode* root)
    {
        if(root == NULL) return 0;

        int lh = size(root -> left);
        int rh = size(root -> right);
        maxi = max(maxi , lh + rh);

        return 1 + max(lh , rh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;
        int lh = size(root -> left);
        int rh = size(root -> right);
        maxi = max(maxi , lh + rh);
        return maxi;
    }
};