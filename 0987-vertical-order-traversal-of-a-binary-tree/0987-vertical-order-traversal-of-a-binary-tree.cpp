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
        map<int,map<int , multiset<int>>> nodes;
        vector<vector<int>> ans;
        queue<pair<TreeNode* , pair<int , int>>> q;
        if(root == NULL) return ans;
        q.push({root , {0 , 0}});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode* temp = it.first;
        int x = it.second.first; 
        int y = it.second.second;
        nodes[x][y].insert(temp -> val);

        if(temp -> left)
        {
            q.push({temp -> left , {x - 1 , y + 1}});
        }
        if(temp -> right)
        {
            q.push({temp -> right , {x + 1 , y + 1}});
        }
    }
     
    for(auto p : nodes)
    {
        vector<int>col;
        for(auto z : p.second)
        {
            col.insert(col.end() , z.second.begin() , z.second.end());
        }
        ans.push_back(col);
    }
    return ans;
    }
};