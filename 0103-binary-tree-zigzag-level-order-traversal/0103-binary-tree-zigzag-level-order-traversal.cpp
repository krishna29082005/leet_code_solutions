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
        queue<struct TreeNode*> q;
        vector<vector<int>> ans;
        int cnt = 0;
        if(root == NULL) return ans;

        q.push(root);

        while(!q.empty())
        {
            
            int size = q.size();
            vector<int> level(size);
            for(int i = 0 ; i < size ; i++)
            {
               TreeNode* node = q.front();
               q.pop();
               if(node -> left != NULL)
               {
                 q.push(node -> left);
               }

               if(node -> right != NULL)
               {
                 q.push(node -> right);
               }
               if(cnt%2 == 1)level[size - i - 1] = node -> val;
               else level[i] = (node -> val);
            }
            ans.push_back(level);
            cnt++;
        }
        return ans;
    }
};