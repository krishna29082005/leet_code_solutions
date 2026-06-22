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
      int needed = n - 1;
      int have = connections.size();
      if(needed > have) return -1;
      disjoint_set ds(n);
      for(auto it : connections){
        int u = it[0];
        int v = it[1];
        ds.union_it(u , v);
      }
      int ans = 0;
      set<int> st;
      for(int i = 0 ; i < n ; i++){
        st.insert(ds.find_par(i));
      }  
      ans = st.size();
      return ans - 1;
    }
};