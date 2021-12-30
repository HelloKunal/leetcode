class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int trend = arr[1] > arr[0];
        int currLen = (arr[0] == arr[1]) ? 1 : 2;
        int maxLen = currLen;
        for(int i = 2; i < arr.size(); i++) {
            if(arr[i] < arr[i-1]) {
                if(trend) currLen++;
                else {
                    currLen = 2;
                }
                trend = false;
            } else if(arr[i] > arr[i-1]) {
                if(!trend) currLen++;
                else {
                    currLen = 2;
                }
                trend = true;
            } else {
                currLen = 1;
            }
            
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};