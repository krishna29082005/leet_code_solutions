class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        while(i < m && j < n){
            if(g[i] <= s[j]){
                cnt++;
                i++;
                j++;
            }
            else if(g[i] > s[j]){
                j++;
            }
            
        }
        return cnt;
    }
};