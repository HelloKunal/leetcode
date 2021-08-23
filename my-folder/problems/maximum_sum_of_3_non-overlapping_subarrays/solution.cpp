class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int nS = nums.size();
        int sum = 0;
        
        int pSum[nS], next[nS], prev[nS];
        for(int i = 0; i < nS; i++)
        {
            if(i == 0) {
                pSum[i] = nums[i];
            } else {
                pSum[i] = pSum[i-1] + nums[i]; 
            }
        }
        sum = 0;
        for(int i = 0; i < nS; i++)
        {
            if(i < k) {
                sum += nums[i];
                next[i] = sum;
            } else {
                sum += nums[i] - nums[i-k];
                next[i] = max(next[i-1], sum);
            }
        }
        sum = 0;
        for(int i = nS-1; i >= 0; i--)
        {
            if(i >= nS-k) {
                sum += nums[i];
                prev[i] = sum;
            } else {
                sum += nums[i] - nums[i+k];
                prev[i] = max(prev[i+1], sum);
            }
        }
        
        sum = 0;
        int lsum, rsum, midIndex;
        int lIndex, rIndex;
        for(int i = k; i <= nS-(2*k); i++) {
            int t = next[i-1] + prev[i+k] + (pSum[i+k-1] - pSum[i-1]);
            if (t > sum) {
                sum = t;
                midIndex = i;
                lsum = next[i-1];
                rsum = prev[i+k];
                
            }
        }
        for(int i = k-1; i < midIndex; i++) {
            if (i - k < 0) {
                if(pSum[i] == lsum) {
                    lIndex = i - k + 1;
                    break;                    
                }
            } else if(pSum[i] - pSum[i-k] == lsum) {
                lIndex = i - k + 1;
                break;
            }
        }
        for(int i = midIndex+(2*k)-1; i < nS; i++) {
            if(pSum[i] - pSum[i-k] == rsum) {
                rIndex = i - k + 1;
                break;
            }
        }
        vector<int> res;
        res.push_back(lIndex);
        res.push_back(midIndex);
        res.push_back(rIndex);
        return res;
    }
};