class Solution {
public:
    bool iscycle(int i , vector<vector<int>>& graph , vector<int>& vis , 
    vector<int>& pathvis){
        vis[i] = 1;
        pathvis[i] = 1;

        for(auto it : graph[i]){
            if(!vis[it]){
                if(iscycle(it , graph , vis , pathvis) == true)
                return true;
            }
            else if(pathvis[it] == 1 && vis[it] == 1){
                return true;
            }
        }
        pathvis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        vector<int> vis(n , 0);
        vector<int> pathvis(n , 0);
        if(iscycle(i , graph , vis , pathvis) == false){
            ans.push_back(i);
        }
        else {
            continue;
        }
     }   
     return ans;
    }
};