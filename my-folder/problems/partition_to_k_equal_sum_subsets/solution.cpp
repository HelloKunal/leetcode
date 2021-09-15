class Solution {
public:
    bool ans = false;
    bool partitionUtil(vector<int> &nums, vector<int> subsetSum, vector<bool> taken, int subset, int n, int k, int curr, int limit) {
        if(subsetSum[curr] == subset) {
            if(curr == k-2) return true;
            return partitionUtil(nums, subsetSum, taken, subset, n, k, curr+1, n-1);
        }
        
        for(int i = limit; i >= 0; i--) {
            if(taken[i]) continue;
            int tmp = nums[i] + subsetSum[curr];
            
            if(tmp <= subset) {
                taken[i] = true;
                subsetSum[curr] += nums[i];
                bool nxt = partitionUtil(nums, subsetSum, taken, subset, n, k, curr, i-1);
                taken[i] = false;
                subsetSum[curr] -= nums[i];
                if(nxt) return true;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sumNums = 0;
        for(int i : nums) {
            sumNums += i;
        }
        if(k == 1) {
            return true;
        }
        if(k > nums.size() || sumNums % k != 0) {
            return false;
        }
        
        int subset = sumNums/k;
        vector<bool> taken(nums.size(), false);
        vector<int> subsetSum(k, 0);
        
        subsetSum[0] = nums[nums.size()-1];
        taken[nums.size()-1] = true;
        return partitionUtil(nums, subsetSum, taken, subset, nums.size(), k, 0, nums.size()-1);
    }
};