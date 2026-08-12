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
    vector<int> rightSideView(TreeNode* root) {
    map<int , int> mp;// level , val
    vector<int> ans;
    queue<pair<TreeNode* , int>>q; // node , level
    if(root == NULL) return ans;

    q.push({root , 0});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode* temp = it.first;
        int lev = it.second;
        mp[lev] = temp -> val;

        if(temp -> left != NULL){
            q.push({temp -> left , lev + 1});
        }
        if(temp -> right != NULL){
            q.push({temp -> right , lev + 1});
        }
    }
    
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
    } 
};