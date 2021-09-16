class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10001, 0); 
        int maxi = 0;
        for(int i : nums) {
            arr[i] += i;
            maxi = max(maxi, i);
        }
        
        int n = 10000;
        int v1 = arr[1], v2 = max(v1, arr[2]);
        for(int i = 3; i <= maxi; i++) {
            int tmp = v2;
            v2 = max(v2, v1+arr[i]);
            v1 = tmp;
        }
        
        return v2;
    }
};