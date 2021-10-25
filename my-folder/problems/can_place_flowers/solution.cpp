class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, j = flowerbed.size()-1, c1 = 0, c2 = 0;
        while(i < flowerbed.size() && flowerbed[i++] == 0) c1++;
        while(j >= 0 && flowerbed[j--] == 0) c2++;
        
        int sum = 0;
        if(c1 == flowerbed.size()) {
            if(c1 % 2 == 0) sum += c1/2;
            else sum += (c1/2) + 1;
        } else {
            int count = 0;
            for(int k = i; k <= j+1; k++) {
                if(flowerbed[k] == 1) {
                    if(count != 0) {
                        if(count % 2 == 0) sum += (count/2) - 1;
                        else sum += count/2;
                        
                        count = 0;
                    }
                } else count++;
            }
            
            sum += c1/2;
            sum += c2/2;            
        }
        
        if(sum >= n) return true;
        else return false;
    }
};