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
    TreeNode* helper(vector<int> &preorder , int ps , int pe, 
                    vector<int> &inorder , int is , int ie,
                    map<int , int> inmap)
                                     {
                                        if(ps > pe || is > ie) return NULL;
                                        TreeNode* root = new TreeNode(preorder[ps]);
                                        int inroot = inmap[preorder[ps]];
                                        int numleft = inroot - is;
                                        root -> left = helper(preorder , ps + 1 , ps + numleft,
                                                              inorder , is , inroot - 1 ,inmap);
                                        root -> right = helper(preorder , ps + numleft + 1 , pe,
                                                               inorder , inroot + 1 , ie  , inmap);
                                        return root;
                                     }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inor;
        for(int i = 0 ; i < preorder.size() ; i++) 
        {
            inor.push_back(preorder[i]);
        }
        sort(inor.begin() , inor.end());
        map<int , int> inmap;
        for(int i = 0 ; i < inor.size() ; i++){
            inmap[inor[i]] = i;
        }
        TreeNode* root;
        root = helper(preorder , 0 , preorder.size() - 1
                     ,inor , 0 , inor.size() - 1 ,
                      inmap);
        return root;                  
    }
    
};