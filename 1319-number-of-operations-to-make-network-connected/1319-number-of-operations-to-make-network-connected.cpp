class disjoint_set{
    public:
    vector<int> size , parent;
    public:
    disjoint_set(int n){
        size.resize(n , 1);
        parent.resize(n );
        for(int i = 0; i < n ; i++){
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1)
            return -1;

        disjoint_set ds(n);

        for(auto it : connections){
            ds.union_it(it[0], it[1]);
        }

        int components = 0;

        for(int i = 0; i < n; i++){
            if(ds.find_par(i) == i)
                components++;
        }

        return components - 1;
    }
};