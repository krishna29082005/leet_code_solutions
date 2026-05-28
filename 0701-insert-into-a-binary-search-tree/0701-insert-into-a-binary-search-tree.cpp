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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) 
        return root = new TreeNode(val);
        TreeNode* cur = root;
        TreeNode* cur2 = NULL;
        while(cur != NULL)
        {
            if(cur -> val > val){
                cur2 = cur;
                cur = cur -> left;
            }
            else{
                cur2 = cur;
                cur = cur -> right;
            }
        }

        if(cur2 -> val < val){
        cur2 -> right = new TreeNode (val);
        }
        else{
        cur2 -> left = new TreeNode (val);
        }
        return root;
    }
};