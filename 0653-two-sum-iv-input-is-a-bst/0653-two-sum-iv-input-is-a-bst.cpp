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
      vector<int> helper(TreeNode* root){
      vector<int>ans;
      if(root == NULL) return ans;
      TreeNode* cur = root;
      while(cur != NULL){
        if(cur -> left == NULL){
            ans.push_back(cur -> val);
            cur = cur -> right;
        }
        else{
            TreeNode* prev = cur -> left;
            while(prev -> right != NULL && prev -> right != cur){
                prev = prev -> right;
            }
            if(prev -> right == NULL)
            {
                prev -> right = cur;
                cur = cur -> left;
            }
            if(prev -> right == cur){
                prev -> right = NULL;
                ans.push_back(cur -> val);
                cur = cur -> right;
            }
        }
      }  
      return ans;
      }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        vector<int> ans = helper(root);
        int i = 0;
        int j = ans.size() - 1;
        while(i < j){
            if(ans[i] + ans[j] == k)
            return true;
            if(ans[i] + ans[j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};