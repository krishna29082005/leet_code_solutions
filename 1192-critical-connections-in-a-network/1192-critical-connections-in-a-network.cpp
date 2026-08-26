
class Solution {
private:
int timer = 1;

public:
    void dfs(int node , int parent , int tin[] , int low[] , vector<vector<int>>& adj , vector<vector<int>>& ans , vector<int>&vis){
        vis[node] = 1;

        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
  
            if(vis[it] == -1){
            dfs(it , node , tin , low , adj , ans , vis);

            low[node] = min(low[it] , low[node]);

            if(low[it] > tin[node]){
                vector<int>temp;
                temp.push_back(node);
                temp.push_back(it);
                ans.push_back(temp);
            }
            }
            else{
                low[node] = min(low[node] , tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<vector<int>> adj(n);
       for(auto it : connections)
       {
          int u = it[0];
          int v = it[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
       }

       int tin[n];
       int low[n];
       vector<int>vis(n , -1);
       vector<vector<int>>ans;
       for(int i = 0 ; i < n ; i++){
          if(vis[i] == -1){
            dfs(0 , -1 , tin , low , adj , ans , vis);
          }
       }
       return ans;
    }
};