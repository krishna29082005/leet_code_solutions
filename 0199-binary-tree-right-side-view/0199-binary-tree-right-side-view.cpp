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
    map<int , int> mp;//level , node
    queue<pair<TreeNode* , int>>q;//node , level for traversal
    vector<int>ans;
    if(root == NULL) return ans;
    q.push({root , 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int value = it.first -> val;
        int level = it.second;
        mp[level] = value;
        
        if(it.first -> left != NULL){
            q.push({it.first -> left , level + 1});
        }
        if(it.first -> right != NULL){
            q.push({it.first -> right , level + 1});
        }
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
    } 
};