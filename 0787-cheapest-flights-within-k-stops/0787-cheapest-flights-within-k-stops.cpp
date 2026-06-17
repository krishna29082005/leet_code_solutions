class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : flights){
            int u = it[0];
            int v = it[1];
            int price = it[2];

            adj[u].push_back({v, price});
        }

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}}); // {stops, {node, cost}}

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node  = it.second.first;
            int cost  = it.second.second;

            if(stops > k) continue;

            for(auto nbr : adj[node]){

                int nextNode = nbr.first;
                int price    = nbr.second;

                int newCost = cost + price;

                if(newCost < dist[nextNode]){

                    dist[nextNode] = newCost;

                    q.push({stops + 1,
                           {nextNode, newCost}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};