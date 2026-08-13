class Solution {
public:
    void dfs(int root , vector<vector<int>>& isConnected , vector<int>& vis){
        vis[root] = 1;
        for(int j = 0 ; j < isConnected[0].size() ; j++){
            if(isConnected[root][j] == 1){
                if(vis[j] == -1){
                    dfs(j , isConnected , vis);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n , -1);
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == -1){
                cnt++;
                dfs(i , isConnected , vis);
            }
        }
        return cnt;
    }
};