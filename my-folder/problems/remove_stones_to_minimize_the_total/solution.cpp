class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int numberOfPiles = piles.size();
        
        make_heap (piles.begin(), piles.end());
        
        for (int i = 0; i < k; i++)
        {
            int maxPile = piles.front();
            
            pop_heap (piles.begin(), piles.end());
            piles.pop_back();
            
            piles.push_back (maxPile - floor (maxPile / 2));
            push_heap (piles.begin(), piles.end());
        }
                
        int sumOfPiles = 0;
        for (int i = 0; i < numberOfPiles; i++)
        {
            sumOfPiles += piles[i];
        }
        
        return sumOfPiles;
    }
};