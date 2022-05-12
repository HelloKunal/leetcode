class Solution {
public:
    bool queryString(string s, int n) {
        int N = n;
        string S = s;
    
        for (int i = N; i > N / 2;  --i) {
            string b = bitset<32>(i).to_string();
            cout<<b.find("1")<<endl;
            cout<<b.substr(b.find("1"))<<endl;
            if (S.find(b.substr(b.find("1"))) == string::npos)
                return false;
        }
        return true;
    }
};