class disjoint_set{
    public:
    vector<int> rank , parent, size;
    public:
    disjoint_set(int n){
        rank.resize(n + 1 , 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);  // Initialize size of each component as 1
        for(int i = 0; i < n + 1 ; i++){
            parent[i] = i;
        }
    }
    int find_par(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = find_par(parent[node]);
    }

    void union_it(int u , int v){
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv)return ;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void union_size(int u , int v){
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else if(size[pv] < size[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n = accounts.size();
       unordered_map<string , int>mp;
       disjoint_set ds(n);
       for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j < accounts[i].size() ; j++){
            string mail = accounts[i][j];
            if(mp.find(mail) == mp.end()){
                mp[mail] = i; 
            }else{
                ds.union_size(i , mp[mail]); 
            }
        }
       }
       vector<string> ans[n];
       for(auto it : mp){
        string mail = it.first;
        int node = ds.find_par(it.second);
        ans[node].push_back(mail);
       }

       vector<vector<string>> res;
       for(int i = 0 ; i < n ; i++){
        if(ans[i].size() == 0) continue;
           sort(ans[i].begin() , ans[i].end());
           vector<string> temp;
           temp.push_back(accounts[i][0]);
           for(auto it : ans[i])
           {
            temp.push_back(it);
           }
           res.push_back(temp);
    }
    
    return res;
    }
};