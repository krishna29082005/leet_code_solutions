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
        map<int , int> inmap;
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inmap[inorder[i]] = i;
        }
        TreeNode* root = bt(preorder , 0 , preorder.size() - 1,
                            inorder , 0 , inorder.size() - 1, inmap);
        return root;
    }
    TreeNode* bt(vector<int> &preorder , int ps , int pe ,
                 vector<int> &inorder , int is , int ie , map<int , int> &inmap)
                 {
                    if(ps > pe || is > ie) return NULL;

                    TreeNode* root = new TreeNode(preorder[ps]);

                    int inroot = inmap[root -> val];
                    int numl = inroot - is;

                    root -> left = bt(preorder , ps + 1 , ps + numl,
                                      inorder , is , inroot - 1 , inmap);

                    root -> right = bt(preorder , ps + numl + 1 , pe,
                                       inorder , inroot + 1 , ie , inmap);
                    return root;
                 }
};