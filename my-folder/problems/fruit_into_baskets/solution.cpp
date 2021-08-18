class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int noOfTrees = fruits.size();
        int res = INT_MIN;
        
        int i = 0, j = 0;
        unordered_map<int, int> um;
        
        for (i = 0; i < noOfTrees; i++)
        {
            um[fruits[i]]++;
            
            while (um.size() > 2 && j < noOfTrees)
            {
                um[fruits[j]]--;
                if (um[fruits[j]] == 0)
                    um.erase(fruits[j]);
                
                j++;
            }
            
            res = max(res, i-j+1);
        }
        
        return res == INT_MIN ? (um.size() > 0 ? noOfTrees : 0) : res;   
    }
};