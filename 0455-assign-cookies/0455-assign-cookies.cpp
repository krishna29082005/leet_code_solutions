class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < m && j < n){
            if(g[i] <= s[j]){
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};