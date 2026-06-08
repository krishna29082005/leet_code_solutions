class Solution {
public:
    bool dfs(int i , vector<vector<int>> &adj , vector<int>& vis , vector<int>& pathvis)
    {
       vis[i] = 1;
       pathvis[i] = 1;

       for(auto it : adj[i]){
           if(!vis[it]) { 
               if(dfs(it , adj , vis ,pathvis) == false)
               return false;
           }
           else if(pathvis[it] == 1){
               return false;
           }
       }
       pathvis[i] = 0;
       return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int e = prerequisites.size();
        for(int i = 0 ; i < e ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> vis(numCourses , 0);
        vector<int> pathvis(numCourses , 0);
        for(int i = 0 ; i < numCourses ; i++){
            if(dfs(i , adj , vis , pathvis) == false) return false;
            
        }
        return true;
    }
};