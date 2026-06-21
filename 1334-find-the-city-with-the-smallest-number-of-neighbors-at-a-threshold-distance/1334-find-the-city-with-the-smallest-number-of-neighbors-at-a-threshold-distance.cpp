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
        for(int i = 0; i < n; i++) {


        vector<int>dis(n , INT_MAX);
        priority_queue<pair<int , int>,
                       vector<pair<int , int>>,
                       greater<pair<int , int>>>pq;
        pq.push({0 , i});
        dis[i] = 0;

        while(!pq.empty()){
            int curdis = pq.top().first;
            int temp = pq.top().second;
            pq.pop();
            if(curdis > dis[temp]) continue;
            for(auto it : adj[temp]){
                int t_temp = it.first;
                int t_dis = it.second;
                if(dis[temp] + t_dis < dis[t_temp]){
                    dis[t_temp] = dis[temp] + t_dis;
                    pq.push({dis[temp] + t_dis , t_temp});
                }
            }
        }
        int cnt = 0;
        for(int j = 0 ; j < n ; j++){
            if(dis[j] <= distanceThreshold){
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