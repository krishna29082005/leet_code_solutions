class disjoint_set{
    public:
    vector<int> rank , parent, size;
    public:
    disjoint_set(int n){
        rank.resize(n + 1 , 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);  // Initialize size of each component as 1
        for(int i = 0; i < n + 1 ; i++){
            parent[i] = i;
        }
    }
    int find_par(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = find_par(parent[node]);
    }

    void union_it(int u , int v){
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv)return ;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void union_size(int u , int v){
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else if(size[pv] < size[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
private:
    int timer = 1;
    void dfs(int node , int parent , vector<int> &vis , vector<vector<int>> & adj , int tim[] , int low[] , vector<vector<int>>& bridges){
        if(vis[node] == 1) return;
        vis[node] = 1;
        tim[node] = low[node] = timer;
        timer++;
    
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
               dfs(it , node , vis , adj , tim , low , bridges);
               low[node] = min(low[node] , low[it]);
               if(low[it] > tim[node]){
                  bridges.push_back({it , node});
               }
            } 
                low[node] = min(low[node] , low[it]);
            
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n , 0);
        int tim[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0 , -1 , vis , adj , tim , low ,bridges);
        return bridges;
    }
};