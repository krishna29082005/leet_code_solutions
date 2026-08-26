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
        int m = grid[0].size();

        disjoint_set ds(n*m);
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) continue;

                int dr[4] = {-1 , 0 , 1 , 0};
                int dc[4] = {0 , 1 , 0 , -1};

                for(int k = 0 ; k < 4 ; k++){
                    int nx = i + dr[k];
                    int ny = j + dc[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        int newnode = nx*m + ny;
                        int oldnode = i*m + j;
                        ds.union_size(newnode , oldnode);
                    }
                } 
                maxi = max(maxi , ds.size[ds.find_par(i*m + j)]);
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) continue;
                set<int> compo;
                int dr[4] = {-1 , 0 , 1 , 0};
                int dc[4] = {0 , 1 , 0 , -1};

                for(int k = 0 ; k < 4 ; k++){
                    int nx = i + dr[k];
                    int ny = j + dc[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        int newnode = nx*m + ny;
                        compo.insert(ds.find_par(newnode));
                    }
                }
                int sum = 0;
                for(auto it : compo){
                    sum += ds.size[it];
                } 
                maxi = max(sum + 1, maxi);
            }
        }
        return maxi;
    }
};