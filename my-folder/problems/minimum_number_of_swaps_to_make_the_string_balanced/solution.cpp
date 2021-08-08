class Solution {
public:
    int minSwaps(string s) {
        int sLength = s.length();
        int minNumberOfSwaps = 0;
        int forwardBracketSum = 0;
        int bestjFromRight = sLength - 1;
        for (int i = 0; i < sLength; i++)
        {
            forwardBracketSum += (s[i] == '[') ? 1 : -1;
            if (forwardBracketSum < 0)
            {
                forwardBracketSum -= (s[i] == '[') ? 1 : -1;
                int backwardBracketSum = 0;
                for (int j = bestjFromRight; j >= 0; j--)
                {
                    backwardBracketSum += (s[j] == ']') ? 1 : -1;
                    if (backwardBracketSum < 0)
                    {
                        minNumberOfSwaps++;
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                        bestjFromRight = j;
                        break;
                    }
                }
                i--;                                
            }
        }
        
        return minNumberOfSwaps++;
    }
};