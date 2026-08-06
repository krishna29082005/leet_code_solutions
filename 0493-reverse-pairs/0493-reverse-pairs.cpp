class Solution {
public:

    void merge(vector<int>& nums , int l , int mid , int r){
        int left = l;
        int right = mid + 1;
        vector<int>temp;
        while(left <= mid && right <= r){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= r){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = l ; i <= r ; i++){
            nums[i] = temp[i - l];
        }
    }
    void countpair(vector<int>& nums , int l , int mid , int r , long long & cnt){
        int j = mid + 1;
           for(int i = l ; i <= mid ; i++){
            while(j <= r && nums[i] > 2LL*nums[j]){
               j++;
            }
            cnt += j - (mid + 1);
           }
        
    }
    void mergesort(vector<int>& nums , int l , int r , long long & cnt){
        if(l >= r) return;
        int mid = (l + r)/2;
        mergesort(nums , l , mid , cnt);
        mergesort(nums , mid + 1 , r , cnt);
        countpair(nums , l , mid , r , cnt);
        merge(nums , l , mid , r);
    }
    int reversePairs(vector<int>& nums) {
        long long cnt = 0;
        mergesort(nums, 0, nums.size() - 1 , cnt);
        return cnt;
    }
};
