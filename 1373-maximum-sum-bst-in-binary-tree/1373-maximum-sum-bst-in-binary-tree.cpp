

class Solution {
public:
    struct info{
        bool isbst;
        long long sum;
        int mn;
        int mx;
        info(bool bst , long long s , int min , int max){
            isbst = bst;
            sum = s;
            mn = min;
            mx = max;
        }
    };

    info helper(TreeNode* root , long long& maxi){
        if(root == NULL){
            return info(true , 0 , INT_MAX , INT_MIN);
        }


        info lh = helper(root -> left , maxi);
        info rh = helper(root -> right , maxi);
         
        if(lh.isbst && rh.isbst && root -> val > lh.mx && root -> val < rh.mn){
        
        long long sum = root -> val + lh.sum + rh.sum;
        maxi = max(maxi , sum);
        int mn = min(root -> val , lh.mn);
        int mx = max(root -> val , rh.mx);
        return info(true , sum , mn , mx);
        }
        return info(false, 0, INT_MIN, INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        long long maxi = 0;
        helper(root , maxi);
        return maxi;
    }
};