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
          vector<int> ans;
          stack<TreeNode*> st1;
          if(root == NULL) return ans;
          st1.push(root);
          while(!st1.empty()){
            root = st1.top();
            st1.pop();
            ans.push_back(root -> val);

            if(root -> right != NULL){
                st1.push(root -> right);
            }
            if(root -> left != NULL){
                st1.push(root -> left);
            }
        }
        return ans;
    }
};