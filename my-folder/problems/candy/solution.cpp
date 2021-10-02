class Solution {
public:
    int candy(vector<int>& ratings) {
        int numChildren = ratings.size();
        vector<int> candies(numChildren, 1);
        
        for(int i = 1; i < numChildren; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        for(int i = numChildren-1; i > 0; i--) {
            if(ratings[i-1] > ratings[i]) {
                candies[i-1] = max(candies[i-1], candies[i]+1);
            }
        }
        
        int res = 0;
        for(int candy : candies) res += candy;
        return res;
    }
};