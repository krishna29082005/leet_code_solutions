class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    int n = numRows;
    vector<vector<int>>temp;
    for(int i = 0 ; i < n ; i++){
        vector<int>row(i + 1 , 1);
        for(int j = 0 ; j <= i ; j++){
            if(j == 0 || j == i){
                row[j] = 1;
            }else{
                row[j] = temp[i - 1][j] + temp[i - 1][j - 1];
            }
        }
        temp.push_back(row);
    }
    return temp;
    }
};