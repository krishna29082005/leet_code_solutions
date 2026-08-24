class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int , int>>>adj(n + 1);
       for(auto it : times){
        int u = it[0];
        int v = it[1];
        int z = it[2];
        adj[u].push_back({v , z});
       }

       priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
       vector<int>dis(n + 1 , INT_MAX);
       pq.push({0 , k});
       dis[k] = 0;
      
       while(!pq.empty()){
        int n = pq.size();
        
        for(int i = 0 ; i < n ; i++){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                int newnode = it.first;
                int newtime = it.second;
                
                int totaltime = newtime + time;
                if(totaltime < dis[newnode]){
                    dis[newnode] = totaltime;
                    pq.push({totaltime , newnode});
                }
            }
        }
        
       }
       int maxi = -1;
       for(int i = 1 ; i <= n ; i++){
          if(dis[i] == INT_MAX) return -1;
          maxi = max(maxi , dis[i]);
       }
       return maxi;
    }
};