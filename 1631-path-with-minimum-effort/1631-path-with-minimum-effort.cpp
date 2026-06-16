class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int , pair<int , int>>,
        vector<pair<int , pair<int , int>>>,
        greater<pair<int , pair<int , int>>>>pq;
        vector<vector<int>> vis(n , vector<int>(m , INT_MAX));
        pq.push({0 , { 0 , 0}});
        vis[0][0] = 0;
        int delrow[4] = {-1 , 0 , 1 , 0};
        int delcol[4] = { 0 , 1 , 0 ,-1};
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if(i == n-1 && j == m-1) return dis;
            pq.pop();
            if(dis > vis[i][j]) continue;
            for(int x = 0 ; x < 4 ; x++){
                int r = i + delrow[x];
                int c = j + delcol[x];
                if(r >= 0 && r < n && c >= 0 && c < m)
                { 
                int tdis = abs(heights[i][j] - heights[r][c]);  
                int newEffort = max(dis, tdis);

                if(newEffort < vis[r][c]){
                   vis[r][c] = newEffort;
                   pq.push({newEffort, {r, c}});
               }
            }
        }
        }
        return -1;
    }
};