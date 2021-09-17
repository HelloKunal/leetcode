class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1;
        unordered_map<int, int> hashMap;
        for(int num : arr) {
            hashMap[num] = hashMap[num - difference] + 1;
            res = max(res, hashMap[num]);
        }
        
        return res;
    }
};