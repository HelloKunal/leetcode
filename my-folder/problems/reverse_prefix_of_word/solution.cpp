class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        string newWord = "";
        for(int j = i; j >= 0; j--) {
            newWord += word[j];
        }
        for(int j = i+1; j < word.length(); j++) {
            newWord += word[j];
        }
        return newWord;
    }
};