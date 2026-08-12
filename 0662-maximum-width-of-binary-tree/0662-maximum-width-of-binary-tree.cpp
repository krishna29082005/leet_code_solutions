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
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode* , int>>q;
        int ans = -1;
        if(root == NULL) return 0;
        q.push({root , 0});

        while(!q.empty()){

            int n = q.size();
            int mini = q.front().second;
            int first , last;

            for(int i = 0 ; i < n ; i++){
                auto it = q.front();
                q.pop();
                long long cid = it.second - mini;
                
                if(i == 0) first = cid;
                if(i == n - 1) last = cid;

                if(it.first -> left != NULL){
                    q.push({it.first -> left , 2*cid + 1});
                }
                if(it.first -> right != NULL){
                    q.push({it.first -> right , 2*cid + 2});
                }
            }
            ans = max(ans , last - first + 1);
        }
        return ans;
    } 
};