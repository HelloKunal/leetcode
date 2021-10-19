class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        
        vector<int> leftMaxArr(n);
        vector<int> rightMaxArr(n);
        leftMaxArr[0] = height[0], rightMaxArr[n-1] = height[n-1];
        for(int i = 1; i < n; i++) leftMaxArr[i] = max(leftMaxArr[i-1], height[i]);
        for(int i = n-2; i >= 0; i--) rightMaxArr[i] = max(rightMaxArr[i+1], height[i]);
        
        for(int i = 1; i < n-1; i++) {            
            res += min(leftMaxArr[i], rightMaxArr[i]) - height[i];
        }
        
        return res;        
    }
};