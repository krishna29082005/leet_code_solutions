class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
        priority_queue<pair<int , pair<int , int>>, 
        vector<pair<int , pair<int , int>>>,
        greater<pair<int , pair<int , int>>>>pq;//declaring a min heap;
        vector<vector<int>>vis(n , vector<int>(n , INT_MAX));
        pq.push({1 ,{ 0 , 0}});
        vis[0][0] = 1;
        int delr[8] = {-1 , 0 , 1 , 0 , -1 , -1 , 1 , 1};
        int delc[8] = {0 , 1 , 0 , -1 , -1 , 1 , 1 , -1};
        while(!pq.empty()){
            auto temp = pq.top();
            int dis = temp.first;
            int ni = temp.second.first;
            int nj = temp.second.second;
            pq.pop();
             
            for(int i = 0 ; i < 8 ; i++){
                int nrow = ni + delr[i];
                int ncol = nj + delc[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == 0 && vis[nrow][ncol] > dis + 1){
                    vis[nrow][ncol] = dis + 1;
                    pq.push({dis + 1 , {nrow , ncol}});
                }
            }
        }
        
        int ans = vis[n - 1][n - 1];
        if(ans == INT_MAX)return -1;
        return ans;
    }
};