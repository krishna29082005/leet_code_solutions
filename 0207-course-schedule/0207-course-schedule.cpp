class Solution {
public:
    int flag = 1;
    void dfs(int i , vector<vector<int>> &adj , vector<int>& vis , stack<int>& st , int start)
    {
       vis[i] = 1;
       for(auto it : adj[i]){
           if(it == start) 
           {flag = 0;
            break;
           }
           if(!vis[it]){
               dfs(it , adj , vis , st , start);
           }
       }
       st.push(i);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int e = prerequisites.size();
        for(int i = 0 ; i < e ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        stack<int> st;
        
        for(int i = 0 ; i < numCourses ; i++){
            vector<int> vis(numCourses , 0);
            if(!vis[i]){
            int start = i;
            dfs(i , adj , vis , st , start);
            }
        }
        if(flag == 0) return false;
        return true;
    }
};