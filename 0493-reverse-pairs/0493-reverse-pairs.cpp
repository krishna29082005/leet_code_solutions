class Solution {
public:
long long cnt = 0;
    void merge(vector<int>& arr , int l , int mid , int r)
    {
        int left = l;
        int right = mid + 1;
        vector<int>temp;
        while(left <= mid && right <= r)
        {
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= r){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = l ; i <= r ; i++){
            arr[i] = temp[i - l];
        }
    }
    void countpair(vector<int>&arr , int l , int mid , int r){
        int j = mid + 1;
        for(int i = l ; i <= mid ; i++){

            while(j <= r && arr[i] > 2LL*arr[j]){
                j++;
            }
            cnt += j - (mid + 1);
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r) return;
        int mid = (l + r)/2;
        mergeSort(arr , l , mid);
        mergeSort(arr , mid + 1 , r);
        countpair(arr , l , mid , r);
        merge(arr , l , mid , r);
    }
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
