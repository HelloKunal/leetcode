bool cmp(string a, string b)
{
    if(a.length() > b.length()) {
        string temp = "";
        for(int i = 0, y = a.length()-b.length(); i < y; i++) {
            temp += "0";
        }
        b = temp + b;
    } else if(b.length() > a.length()) {    
        string temp = "";
        for(int i = 0, y = b.length()-a.length(); i < y; i++) {
            temp += "0";
        }
        a = temp + a;
    }
    
    if(a.compare(b) > 0)
        return true;
    else
        return false;
}

class Solution {
public:
       
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};