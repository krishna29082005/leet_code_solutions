class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int e = prerequisites.size();
        for(int i = 0 ; i < e ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> indeg(numCourses , 0);
        vector<int> ans;
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        for(int i = 0 ; i < numCourses ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);

            for(auto it : adj[temp]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        if(numCourses == ans.size()) return true;
        return false;
    }
};