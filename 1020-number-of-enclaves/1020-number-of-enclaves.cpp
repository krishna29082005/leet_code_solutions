class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int , int>>q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && (i == 0 || i == m - 1 
                                      || j == 0 || j == n - 1)){
                vis[i][j] = -1;
                q.push({i , j});
            }
            else{
                vis[i][j] = -2;
            }
            }
            }
        int delrow[4] = {-1 , 0 , 1 , 0};
        int delcol[4] = {0 , 1 , 0 , -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = -1;
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && 
                   grid[nrow][ncol] == 1 && vis[nrow][ncol] == -2){
                   vis[nrow][ncol] = -1;
                   q.push({nrow , ncol});
            }
        }
        }
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(vis[i][j] == -2 && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};