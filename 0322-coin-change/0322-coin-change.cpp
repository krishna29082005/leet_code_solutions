class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<pair<int , int>>q;
        int n = coins.size();
        vector<int>vis(amount + 1 , -1);

        q.push({0 , amount});
        vis[amount] = 1;


        while(!q.empty()){
            int no = q.front().first;
            int temp = q.front().second;
            if(temp == 0) return no;
            q.pop();
            

            for(int i = 0 ; i < n ; i++){
                if(temp - coins[i] >= 0){
                    
                   int node = temp - coins[i];

                   if(vis[node] == -1){
                        vis[node] = 1;
                        q.push({no + 1, node});
                    }                   
                }
            }
        }
        return -1;
    }
};