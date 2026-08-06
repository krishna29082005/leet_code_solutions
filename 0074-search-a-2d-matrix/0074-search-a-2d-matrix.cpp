class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int row = matrix.size();
     int col = matrix[0].size();

     int low = 0;
     int high = row - 1;
     while(low <= high)
     {
        int mid = (low + high)/2;
        if (matrix[mid][0] <= target && target <= matrix[mid][col - 1])
        {
            int low1 = 0;
            int high1 = col - 1;
            while(low1 <= high1)
            {
                int mid1 = (low1 + high1)/2;
                if(target == matrix[mid][mid1])
                return true;

                else if(target < matrix[mid][mid1])
                high1 = mid1 - 1;

                else{
                    low1 = mid1 + 1;
                }
            }
            return false;
        }

        else if(target > matrix[mid][col - 1]){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }
            return false;
    }
};