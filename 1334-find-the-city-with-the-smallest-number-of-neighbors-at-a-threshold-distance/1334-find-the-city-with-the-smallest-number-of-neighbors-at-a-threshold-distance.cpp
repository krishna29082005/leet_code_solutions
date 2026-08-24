class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int , int>>>adj(n);
        int e = edges.size();
        for(int i = 0 ; i < e  ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }
        int mini = INT_MAX;
        int ans = -1;
        for(int i = 0 ; i < n ; i++){

            vector<int>vis(n , INT_MAX);
            priority_queue<pair<int , int> , vector<pair<int , int>> , 
            greater<pair<int , int>>>pq;
            pq.push({0 , i});
            vis[i] = 0;
            while(!pq.empty()){
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                for(auto it : adj[node]){
                    int newnode = it.first;
                    int newdis = it.second;

                    if(vis[newnode] > dis + newdis)
                    {
                        vis[newnode] = dis + newdis;
                        pq.push({dis + newdis , newnode});
                    }
                }
            }

            int cnt = 0;
            for(int i = 0 ; i < n ; i++){
                if(vis[i] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= mini){
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};