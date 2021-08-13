class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int noOfFlowerbeds = flowerbed.size();
        if (noOfFlowerbeds == 1)
        {
            if (n == 0)
                return true;
            if (n == 1)
                return (flowerbed[0] == 0) ? true : false;
            else
                return false;
        }
        
        for (int i = 0; i < noOfFlowerbeds && n > 0; i++)
        {
            if (i == 0)
            {
                if (flowerbed[i] == 0 && flowerbed[i+1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i == noOfFlowerbeds - 1)
            {
                if (flowerbed[i] == 0 && flowerbed[i-1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;       
                }         
            }
            else if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                n--;                       
            }
        }
        
        return (n == 0) ? true: false;
    }
};