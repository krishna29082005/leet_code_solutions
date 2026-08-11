class info{
    public:
      int minnode;
      int maxnode;
      int sum;

      info(int minnode , int maxnode , int sum){
        this -> minnode = minnode;
        this -> maxnode = maxnode;
        this -> sum = sum;
      }
};
class Solution {
public:
    info helper(TreeNode* root , long long& maxi){
        if(root == NULL){
            return info(INT_MAX , INT_MIN , 0);
        }


        info lh = helper(root -> left , maxi);
        info rh = helper(root -> right , maxi);
         
        if(root -> val > lh.maxnode && root -> val < rh.minnode){
        
        long long sum = root -> val + lh.sum + rh.sum;
        maxi = max(maxi , sum);
        int mn = min(root -> val , lh.minnode);
        int mx = max(root -> val , rh.maxnode);
        return info(mn , mx , sum);
        }
        return info(INT_MIN, INT_MAX ,0);
    }

    int maxSumBST(TreeNode* root) {
        long long maxi = 0;
        helper(root , maxi);
        return maxi;
    }
};