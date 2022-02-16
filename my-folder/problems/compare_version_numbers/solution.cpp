class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        string temp = "";
        vector<int> v1;
        for(char c : version1) {
            if(c != '.') {
                temp += c;
            } else {
                v1.push_back(stoi(temp));
                temp = "";
            }
        }
        if(temp != "") v1.push_back(stoi(temp));
        
        temp = "";
        vector<int> v2;
        for(char c : version2) {
            if(c != '.') {
                temp += c;
            } else {
                v2.push_back(stoi(temp));
                temp = "";
            }
        }
        if(temp != "") v2.push_back(stoi(temp));
        
        int maxSize = max(v1.size(), v2.size());
        while(v1.size() < maxSize) v1.push_back(0);
        while(v2.size() < maxSize) v2.push_back(0);
        
        bool left = false, right = false;
        for(int i = 0; i < maxSize; i++) {
            if(v1[i] < v2[i]) {
                left = true;
                break;
            } else if(v1[i] > v2[i]) {
                right = true;
                break;
            }
        }
        
        if(left) return -1;
        else if(right) return 1;
        return 0;
    }
};