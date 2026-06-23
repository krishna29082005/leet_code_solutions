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
private: 
    bool isvalid(int u , int v , int n){
        return (u >= 0 && u < n && v >= 0 && v < n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint_set ds(n*n);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) continue;
                int dr[4] = {-1 , 0 , 1 , 0};
                int dc[4] = {0 , 1 , 0 , -1};
                for(int d = 0 ; d < 4 ; d++){
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if(isvalid(nr , nc , n) && grid[nr][nc] == 1){
                        int nodeno = i*n + j;
                        int anodeno = nr*n + nc; 
                        ds.union_size(nodeno , anodeno);
                    }
                }
            }
        }
        //step 2:
        int mx = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) continue;
                int dr[4] = {-1 , 0 , 1 , 0};
                int dc[4] = {0 , 1 , 0 , -1};
                set<int>component;
                for(int d = 0 ; d < 4 ; d++){
                    int ar = i + dr[d];
                    int ac = j + dc[d];
                    if(isvalid(ar , ac , n) && grid[ar][ac] == 1){
                        component.insert(ds.find_par(ar*n + ac));
                    }
                }
                int sum = 0;
                for(auto it : component){
                    sum += ds.size[it];
                }
                mx = max(mx , sum + 1);
            }
        }
        for(int i = 0 ; i < n ; i++){
            mx = max(mx , ds.size[ds.find_par(i)]);
        }
        return mx;
    }
};