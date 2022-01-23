class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> um;
        for(int i : nums) {
            um[i]++;
        }
        vector<int> res;
        for(auto item : um) {
            int i = item.first;
            if(um.count(i-1) == 0 && um.count(i+1) == 0 && um[i] == 1) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};