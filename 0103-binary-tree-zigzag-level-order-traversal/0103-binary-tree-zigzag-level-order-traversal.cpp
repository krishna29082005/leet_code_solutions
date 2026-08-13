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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        q.push(root);
        int cnt = 0;

        while(!q.empty()){
            int n = q.size();
            vector<int>temp(n);
            for(int i = 0 ; i < n ; i++){
                auto it = q.front();
                q.pop();

                if(it -> left != NULL){
                    q.push(it -> left);
                }
                if(it -> right != NULL){
                    q.push(it -> right);
                }
                if(cnt%2 == 0){
                    temp[i] = it -> val;
                }else{
                    temp[n - i - 1] = it -> val;
                }
            }
            ans.push_back(temp);
            cnt++;
        }
        return ans;
    }
};