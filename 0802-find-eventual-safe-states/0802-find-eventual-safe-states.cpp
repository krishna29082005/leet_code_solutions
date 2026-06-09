class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& state) {

        if(state[node] == 1) return false; // cycle
        if(state[node] == 2) return true;  // already safe
        if(state[node] == 3) return false; // already unsafe

        state[node] = 1; // visiting

        for(auto nxt : graph[node]) {
            if(!dfs(nxt, graph, state)) {
                state[node] = 3;
                return false;
            }
        }

        state[node] = 2; // safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> state(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(dfs(i, graph, state))
                ans.push_back(i);
        }

        return ans;
    }
};