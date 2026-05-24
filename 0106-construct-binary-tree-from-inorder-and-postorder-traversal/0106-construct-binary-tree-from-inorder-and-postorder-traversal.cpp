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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int , int> inmap;
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inmap[inorder[i]] = i;
        }
        TreeNode* root = bt(postorder , 0 , postorder.size() - 1,
                            inorder , 0 , inorder.size() - 1, inmap);
        return root;
    }
     TreeNode* bt(vector<int> &postorder , int ps , int pe ,
                 vector<int> &inorder , int is , int ie , map<int , int> &inmap)
                 {
                    if(ps > pe || is > ie) return NULL;

                    TreeNode* root = new TreeNode(postorder[pe]);

                    int inroot = inmap[root -> val];
                    int numr = ie - inroot;

                    root -> left = bt(postorder , ps , pe - numr -1,
                                      inorder , is , inroot - 1 , inmap);

                    root -> right = bt(postorder , pe - numr , pe - 1,
                                       inorder , inroot + 1 , ie , inmap);
                    return root;
                 }
};