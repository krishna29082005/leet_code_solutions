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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>>mp;
        vector<vector<int>>ans;
        queue<pair<TreeNode* , pair<int , int>>>q;
        if(root == NULL) return ans;
        q.push({root , {0 , 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it.second.first; // verticle axis;
            int y = it.second.second; // level;
            TreeNode* temp = it.first; // node at which we are

            mp[x][y].insert(temp -> val);

            if(temp -> left != NULL){
                q.push({temp -> left , {x - 1 , y + 1}});
            }
            if(temp -> right != NULL){
                q.push({temp -> right , {x + 1 , y + 1}});
            }
        }
        for(auto it : mp){
            vector<int> col;
            for(auto p : it.second){
                col.insert(col.end() , p.second.begin() , p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};