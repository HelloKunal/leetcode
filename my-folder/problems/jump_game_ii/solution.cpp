class Solution {
public:
    
    int jump(vector<int>& nums) {
        int max_so_far = 0, max_selected = 0, res = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            max_so_far = max(max_so_far, i + nums[i]);
            
            if(i == max_selected) {
                res++;
                max_selected = max_so_far;
            }
        }
        
        return res;
    }
};