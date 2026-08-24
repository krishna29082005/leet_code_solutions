class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq;

        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n , vector<int>(m , INT_MAX));

        pq.push({1 , {0 , 0}});
        dis[0][0] = 1;
        
        while(!pq.empty()){
            
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            int dr[8] = {-1 , 0 , 1 , 0 , -1 , 1 , 1 , -1};
            int dc[8] = {0 , 1 , 0 , -1 , 1 , 1 , -1 , -1};

            for(int i = 0 ; i < 8 ; i++){
                int nx = x + dr[i];
                int ny = y + dc[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0){
                    if(dis[nx][ny] > dis[x][y] + 1){
                        dis[nx][ny] = dis[x][y] + 1;
                        pq.push({dis[x][y] + 1 , {nx , ny}});
                    }
                }
            }
        }
        if(dis[n - 1][m - 1] == INT_MAX)return -1;
        return dis[n - 1][m - 1];
    }
};