class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = times.size();
        vector<vector<pair<int , int>>> adj(n + 1);
        for(int i = 0 ; i < t ; i++){
           int u = times[i][0];
           int v = times[i][1];
           int wt = times[i][2];
           adj[u].push_back({v , wt});  
        }
        int maxi = INT_MIN;
        priority_queue<pair<int , int>,
                       vector<pair<int , int>>,
                       greater<pair<int , int>>>pq;
        vector<int>dis(n + 1 , INT_MAX);
        pq.push({0 , k});
        dis[k] = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist > dis[node]) continue;
            for(auto it : adj[node]){
                int nextnode = it.first;
                int cost = it.second;

                int newcost = cost + dist;
                if(newcost < dis[nextnode]){
                    dis[nextnode] = newcost;
                    pq.push({newcost , nextnode});
                }
            }
        }

        for(int i = 1 ; i < n + 1 ; i++){
            if(dis[i] == INT_MAX) return -1;
            maxi = max(maxi , dis[i]);
        }
        return maxi;
    }
};