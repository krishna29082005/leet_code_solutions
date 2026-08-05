class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
       sort(intervals.begin() , intervals.end());
       int n = intervals.size();
       vector<vector<int>>ans;
       int current = 0;
       for(int i = 1 ; i < n ; i++){
           if(intervals[current][1] >= intervals[i][0]){
            intervals[current][1] = max(intervals[current][1] , intervals[i][1]);
           }else{
            ans.push_back(intervals[current]);
            current = i;
           }
       }
       if(current < n){
        ans.push_back(intervals[current]);
       }
       return ans;
    }
};