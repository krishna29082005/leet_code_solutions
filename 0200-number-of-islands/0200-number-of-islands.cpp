class Solution {
public:
    void bfs(int i , int j , vector<vector<char>>& grid , vector<vector<int>>& vis){
        queue<pair<int , int>>q;
        q.push({i , j});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int dr[4] = {-1 , 0 , 1 , 0};
        int dc[4] = {0 , 1 , 0 , -1};
        for(int i = 0 ; i < 4 ; i++){
            int nr = x + dr[i];
            int nc = y + dc[i];
            if(nr >= 0 && nr < n && nc >=0 && nc < m){
                if(grid[nr][nc] == '1' && vis[nr][nc] == -1){
                    q.push({nr , nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , -1));
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(grid[i][j] == '1' && vis[i][j] == -1){
                    vis[i][j] = 1;
                    cnt++;
                    bfs(i , j , grid , vis);
                }
            }
        }
        return cnt;
    }
};