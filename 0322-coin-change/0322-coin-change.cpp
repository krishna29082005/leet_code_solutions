class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<pair<int , int>>q;
        q.push({0 , amount});
        vector<int>vis(amount + 1 , -1);
        vis[amount] = 1;
        while(!q.empty()){
            int step = q.front().first;
            int ca = q.front().second;
            q.pop();

            if(ca == 0) return step;

            for(int i = 0 ; i < coins.size() ; i++){
                if(ca - coins[i] >= 0 && vis[ca - coins[i]] == -1){
                    vis[ca - coins[i]] = 1;
                    q.push({step + 1 , ca - coins[i]});
                }
            }
        }
        return -1;
    }
};