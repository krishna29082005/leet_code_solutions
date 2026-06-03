class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      queue<pair<int , int>> q;
      int n = image.size();
      int m = image[0].size();
      int ori = image[sr][sc];
      int vis[n][m];
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
                vis[i][j] = image[i][j];
        }
      }
      q.push({sr , sc});
      int delrow[] = {-1 , 0 , +1 , 0};
      int delcol[] = {0 , +1 , 0 , -1};
      while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        vis[r][c] = color;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            vis[nrow][ncol] != color && image[nrow][ncol] == ori)
            {
                q.push({nrow , ncol});
                vis[nrow][ncol] = color;
            }
        }
      }
      vector<vector<int>> ans;
      for(int i = 0 ; i < n ; i++){
        vector<int> temp;
        for(int j = 0 ; j < m ; j++){
            temp.push_back(vis[i][j]);
        }
        ans.push_back(temp);
      }
      return ans;
    }
};