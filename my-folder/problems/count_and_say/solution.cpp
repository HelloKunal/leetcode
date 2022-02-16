class Solution {
public:
    string countAndSayUtil(string n) {
        string num = n;
        string res = "";
        for(int i = 0; i < num.length(); i++) {
            int count = 1;
            while(i+1 < num.length() && num[i] == num[i+1]) {
                count++;
                i++;
            }
            
            res += to_string(count);
            res += num[i];
        }
        
        return res;
    }
    string countAndSay(int n) {
        string res = "1";
        for(int i = 0; i < n-1; i++) {
            res = countAndSayUtil(res);
        }
        return res;
    }
};