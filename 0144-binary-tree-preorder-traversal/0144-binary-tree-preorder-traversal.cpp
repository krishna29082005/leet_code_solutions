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
    vector<int> preorderTraversal(TreeNode* root) {
          vector<int> preor;
          stack<TreeNode*> st1;
          st1.push(root);
          if(root == NULL) return preor;
          while(!st1.empty())
          {
            root = st1.top();
            st1.pop();
            preor.push_back(root -> val);
            if(root -> right != NULL)
            { 
              st1.push(root -> right);
            }
             
            if(root -> left != NULL)
            { 
              st1.push(root -> left);
            }
          }
          return preor;
    }
};