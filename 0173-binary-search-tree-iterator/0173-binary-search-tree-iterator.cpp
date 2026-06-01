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
class BSTIterator {
public:
    vector<int> ans;
    int idx = 0;
    BSTIterator(TreeNode* root) {
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
    }
    
    int next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        if(idx >= ans.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */