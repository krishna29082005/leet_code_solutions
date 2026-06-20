class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int r = roads.size();
        const long  MOD = 1e9 + 7;
        vector<vector<pair<int , int>>> adj(n);
        for(int i = 0 ; i < r ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back({v , t});
            adj[v].push_back({u , t});
        }

        priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;
        vector<long long> vis(n, LLONG_MAX);
        vector<int> ways(n , 0);
        pq.push({0 , 0});//dist , node
        vis[0] = 0;
        ways[0] = 1;
    

        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(time > vis[node]) continue;
            for(auto it : adj[node]){
                int temp = it.first;
                long long ctime = it.second;
                
                long long newtime = time + ctime;
                if(newtime < vis[temp]){
                    vis[temp] = newtime;
                    ways[temp] = ways[node];
                    pq.push({newtime , temp});
                }
                else if(newtime == vis[temp]){
                    ways[temp] = (ways[temp] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
        }
};