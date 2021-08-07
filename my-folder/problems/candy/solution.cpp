class Solution {
public:
    int candy(vector<int>& ratings){
        int numberOfChildren = ratings.size();
        if (numberOfChildren < 1)
            return -1;
        
        vector<int> candyDist (numberOfChildren, 1);
        
        for (int i = 1; i < numberOfChildren; i++)
        {
            if (ratings[i] > ratings[i-1])
                candyDist[i] = candyDist[i-1] + 1;
        }
        
        for (int i = numberOfChildren - 1; i > 0; i--)
        {
            if (ratings[i-1] > ratings[i])
                candyDist[i-1] = max (candyDist[i-1], candyDist[i] + 1);
        }
        
        int numberOfCandies = 0;
        for (int i = 0; i < numberOfChildren; i++)
        {
            numberOfCandies += candyDist[i];
        }
        
        return numberOfCandies;
    }
};