class Solution {
public:
    void dfs(int root , vector<vector<int>>& isConnected , vector<int>& vis)
    {
        vis[root] = 1;
        for(int j = 0 ; j < isConnected.size() ; j++){
            if(isConnected[root][j] == 1 && !vis[j]){
                dfs(j , isConnected , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int> vis(size , 0);
        int cnt = 0;
        for(int i = 0 ; i < size ; i++){
            if(vis[i] == 0)
            {
                cnt++;
                dfs(i , isConnected , vis);
            }
        }
        return cnt;
    }
};