class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        bool sIsPrefixString = false;
        int numberOfWords = words.size();
        int sLength = s.length(), sIterator = 0, sRemaining = s.length();
        
        for (int i = 0; i < numberOfWords; i++)
        {
            string word = words[i];
            int wordSize = word.size();
            
            if (wordSize > sRemaining)
                return false;
            
            for (int j = 0; j < wordSize; j++)
            {
                sRemaining--;
                if (s[sIterator++] != word[j])
                    return false;
            }
            
            if (sRemaining == 0)
                return true;
        }        
        return false;
    }
};