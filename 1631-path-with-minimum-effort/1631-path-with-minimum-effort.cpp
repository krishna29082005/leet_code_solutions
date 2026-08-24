class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n = heights.size();
       int m = heights[0].size();
       
       priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>q;
       vector<vector<int>>dis(n , vector<int>(m , INT_MAX));
       q.push({0 , {0 , 0}});
       dis[0][0] = 0;

       while(!q.empty()){
        int maxeff = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();

        int dr[4] = {-1 , 0 , 1 , 0};
        int dc[4] = {0 , 1 , 0 , -1};

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dr[i];
            int ny = y + dc[i];
            
            if(nx >= 0 && nx < n && ny >=0 && ny < m){

            int neweff = max(maxeff , abs(heights[nx][ny] - heights[x][y]));

            if(dis[nx][ny] > neweff){
                dis[nx][ny] = neweff;
                q.push({neweff , {nx , ny}});
            }
            }
          } 
       }
       return dis[n - 1][m - 1];
    }
};