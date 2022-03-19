class Solution {
public:
    
    int get_count(string &S, int ch)
    {
        int count = 0;
        for(int i = 0; i < S.size(); i++)
        {
            count += (S[i] == ch);
        }
        return count;
    }
    
    long long choose_2(long long n)
    {
        return n*(n - 1)/2;
    }
    
    long long maximumSubsequenceCount(string text, string pattern) 
    {
        if(pattern[0] == pattern[1])
        {
            return choose_2(get_count(text, pattern[0]) + 1);
        }
        
        vector <long long> prefix_frequency_1(text.size()), suffix_frequency_2(text.size());
        for(int i = 0; i < text.size(); i++)
        {
            prefix_frequency_1[i] = (text[i] == pattern[0]);
            
            if(i > 0)
            {
                prefix_frequency_1[i] += prefix_frequency_1[i - 1];
            }
        }
        
        for(int i = text.size() - 1; i >= 0; i--)
        {
            suffix_frequency_2[i] = (text[i] == pattern[1]);
            
            if(i < text.size() - 1)
            {
                suffix_frequency_2[i] += suffix_frequency_2[i + 1];
            }
        }
        
        long long answer = 0;
        for(int i = 0; i + 1 < text.size(); i++)
        {
            if(text[i] == pattern[0])
            {
                answer += suffix_frequency_2[i + 1];
            }
        }
        
        long long maximum_increase = max(suffix_frequency_2[0], prefix_frequency_1[text.size() - 1]);
        for(int i = 0; i + 1 < text.size(); i++)
        {
            maximum_increase = max(maximum_increase, suffix_frequency_2[i + 1]);
            maximum_increase = max(maximum_increase, prefix_frequency_1[i]);
        }
        
        answer += maximum_increase;
        
        return answer;
    }
};
