class Solution {
public:
    
    void append(string &S, int alpha, int times)
    {
        for(int i = 1; i <= times; i++)
        {
            S += (char)('a' + alpha); 
        }
    }
    
    string repeatLimitedString(string S, int repeatLimit) 
    {
        const int NO_OF_ALPHABETS = 26; 
        vector <int> frequency(NO_OF_ALPHABETS + 1, 0);
        for(int i = 0; i < S.size(); i++)
        {
            frequency[S[i] - 'a']++;
        }
        
        int no_of_repetitions, last = -1, last_count = 0;
        string answer;
        int alpha_1 = NO_OF_ALPHABETS - 1, alpha_2 = NO_OF_ALPHABETS - 1;
        while(alpha_1 >= 0 || alpha_2 >= 0)
        {
            while(alpha_1 >= 0 && frequency[alpha_1] == 0)
            {
                alpha_1--;
            }
            
            if(alpha_1 >= 0)
            {
                no_of_repetitions = min(repeatLimit - (alpha_1 == last), frequency[alpha_1]);
                append(answer, alpha_1, no_of_repetitions);
                frequency[alpha_1] -= no_of_repetitions;
                last = alpha_1;
            }
            
            alpha_2 = min(alpha_1 - 1, alpha_2); 
            
            while(alpha_2 >= 0 && frequency[alpha_2] == 0)
            {
                alpha_2--;
            }
            
            if(alpha_2 < 0)
            {
                break;
            }
        
            if(alpha_2 >= 0)
            {
                no_of_repetitions = 1;
                append(answer, alpha_2, no_of_repetitions);
                frequency[alpha_2] -= no_of_repetitions;
                last = alpha_2;
            }
        }
        
        return answer;
    }
};
