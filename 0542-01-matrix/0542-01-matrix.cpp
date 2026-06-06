class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int , int> , int>>q;
        vector<vector<int>> vis(m , vector<int>(n , 0));
        vector<vector<int>> dis(m , vector<int>(n , 0));

         for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i , j} , 0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
         }
        int delrow[4] = {-1 , 0 , 1 , 0};
        int delcol[4] = {0 , 1 , 0 , -1};
        while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int step = q.front().second;
        dis[r][c] = step;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
               vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                q.push({{nrow , ncol},step + 1});
               }
        } 
        }
        return dis;
    } 
};