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
    TreeNode* bt(vector<int>& preor , int ps , int pe , 
                 vector<int>& inor , int is , int ie , map<int , int>& inmap){

                    if(is > ie || ps > pe) return NULL;

                    TreeNode* root = new TreeNode(preor[ps]);
                    
                    int inroot = inmap[root -> val];
                    int numl = inroot - is;

                    root -> left = bt(preor , ps + 1 , ps + numl , inor
                                   , is , inroot - 1 , inmap);
                    
                    root -> right = bt(preor , ps + numl + 1 , pe , inor
                                   , inroot + 1 , ie , inmap);
                    return root;
                 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return NULL;
        map<int , int>inmap;
        for(int i = 0 ; i < n ; i++){
            inmap[inorder[i]] = i;
        }    

        return bt(preorder , 0 , n - 1 , inorder , 0 , n - 1 , inmap);
    }
};