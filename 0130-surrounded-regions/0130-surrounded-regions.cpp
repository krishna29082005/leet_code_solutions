class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int , int>>q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'O' && (i == 0 || i == m - 1 
                                      || j == 0 || j == n - 1)){
                vis[i][j] = -1;
                q.push({i , j});
            }
            else{
                vis[i][j] = 0;
            }
            }
            }
      int delrow[] = {-1 , 0 , +1 , 0};
      int delcol[] = {0 , +1 , 0 , -1};
      while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        vis[r][c] = -1;
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && 
             board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = -1;
                q.push({nrow , ncol});
            }      
        }
      }
     for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
            if(vis[i][j] != -1){
                board[i][j] = 'X';
            }
            }
            }
    }
};