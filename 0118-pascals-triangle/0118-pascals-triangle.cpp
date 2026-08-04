class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    int n = numRows;
    vector<vector<int>>temp;
    for(int i = 0 ; i < n ; i++){
        vector<int>row(i + 1);
        row[0] = 1;
        int val = 1;
        for(int j = 1 ; j < i + 1  ; j++){
            val = val*(i + 1 - j)/j;
            row[j] = val;
        }
        temp.push_back(row);
    }
    return temp;
    }
};