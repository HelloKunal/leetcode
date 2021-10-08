class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& temp, int begin, int end) {
        int inv_count = 0, mid = (begin+end)/2;
        if(end > begin) {
            inv_count += mergeSort(nums, temp, begin, mid);
            inv_count += mergeSort(nums, temp, mid+1, end);
            
            inv_count += specialMerge(nums, begin, mid+1, end);
            merge(nums, temp, begin, mid+1, end);
        }
        return inv_count;
    }
    
    int specialMerge(vector<int> &nums, int begin, int mid, int end) {
        
        int i, j, k;
        int inv_count = 0;
        
        i = begin;
        j = mid;
        k = begin;
        
        while((i <= mid-1) && (j <= end)) {
            auto u = 1LL * nums[i];
            auto v = 1LL * nums[j];
            if(u > 2*v) {
                inv_count += mid - i;
                j++;
            } else {
                i++;
            }
        }
        
        return inv_count;
    }
    
    void merge(vector<int>& nums, vector<int>& temp, int begin, int mid, int end) {
        int i, j, k;
        
        i = begin;
        j = mid;
        k = begin;
        
        while((i <= mid-1) && (j <= end)) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while(i <= mid-1) {
            temp[k++] = nums[i++];
        }
        
        while(j <= end) {
            temp[k++] = nums[j++];
        }
        
        for(int i = begin; i <= end; i++) {
            nums[i] = temp[i];
        }
    }
    
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        int res = mergeSort(nums, temp, 0, nums.size()-1);
        return res;
    }
};