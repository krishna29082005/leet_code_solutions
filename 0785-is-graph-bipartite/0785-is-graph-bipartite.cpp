class Solution {
public:
    int  flag = 1;
    void dfs(int i , vector<vector<int>>& graph , vector<int>& color){
            
            for(auto it : graph[i]){
                if(color[it] == -1){
                    color[it] = !color[i];
                    dfs(it , graph , color);
                }
                else if(color[it] == color[i])
                flag = 0;
            } 
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1){
            color[0] = 0;
            dfs(i , graph , color);
            }
            if(flag == 0) return false;
        }
        return true;
    }
};