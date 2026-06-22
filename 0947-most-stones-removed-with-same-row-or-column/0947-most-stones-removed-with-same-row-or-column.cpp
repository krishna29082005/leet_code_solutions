class disjoint_set{
    public:
    vector<int> size , parent;
    public:
    disjoint_set(int n){
        size.resize(n + 1 , 1);
        parent.resize(n + 1);
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
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(size[pv] < size[pu]){
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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        
        for(auto it : stones)
        {
            maxrow = max(maxrow , it[0]);
            maxcol = max(maxcol , it[1]);
        }
        disjoint_set ds(maxrow + maxcol + 1);
        unordered_map<int , int>sn;
        int n = stones.size();
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.union_it(noderow , nodecol);
            sn[noderow] = 1;
            sn[nodecol] = 1;
        }
        int cnt = 0;
        for(auto it : sn){
           if(ds.find_par(it.first) == it.first){
            cnt++;
           }
        }
        return n - cnt;
    }
};