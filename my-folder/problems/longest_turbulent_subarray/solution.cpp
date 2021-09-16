class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int arrSize = arr.size();
        if(arrSize == 1) return 1;
        bool trend = (arr[1] > arr[0]) ? true : false;
        int currLen = (arr[1] == arr[0]) ? 1 : 2;
        int maxLen = currLen;
        for(int i = 2; i < arrSize; i++) {
            if(arr[i] < arr[i-1]) {

                if(trend) currLen += 1;
                else currLen = 2;
                trend = false;
                
            } else if(arr[i] > arr[i-1]) {
                
                if(!trend) currLen += 1;
                else currLen = 2;
                trend = true;
                
            } else {
                currLen = 1;
            }
            
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;           
        
    }
};