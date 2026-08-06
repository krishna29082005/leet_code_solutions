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
        vector<vector<int>> ans;
        queue<pair<TreeNode* , pair<int , int>>>q;
        q.push({root , {0 , 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            mp[x][y].insert(it.first -> val);

            if(it.first -> left != NULL){
                q.push({it.first -> left , {x - 1 , y + 1}});
            }
            if(it.first -> right != NULL)
            {
                q.push({it.first -> right , {x + 1 , y + 1}});
            }
        }
        for(auto it : mp)
        {
            vector<int>temp;
            for(auto p : it.second){
                temp.insert(temp.end() , p.second.begin() , p.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};