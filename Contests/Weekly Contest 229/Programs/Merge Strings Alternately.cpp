class Solution 
{
    public:
    string mergeAlternately(string word1, string word2) 
    {
        string answer;
        for(int i = 0, j = 0, k = 0; i < word1.size() || j < word2.size(); k++)
        {
            if(k%2 == 0)
            {
                if(i < word1.size())
                {
                    answer += word1[i++];
                }
                else 
                {
                    answer += word2[j++];
                }
            }
            else 
            {
                if(j < word2.size())
                {
                    answer += word2[j++];
                }
                else 
                {
                    answer += word1[i++];
                }
            }
        }
        
        return answer;
    }
};
