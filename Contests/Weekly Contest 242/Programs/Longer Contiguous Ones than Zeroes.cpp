class Solution {
public:
    bool checkZeroOnes(string s) 
    {
        int zeroes = 0, ones = 0;
        
        int zeroes_here = 0, ones_here = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            switch(s[i])
            {
                case '0': zeroes_here++;
                          ones_here = 0;
                          break;
                    
                case '1': ones_here++;
                          zeroes_here = 0;
                    
            }
            
            zeroes = max(zeroes, zeroes_here);
            ones = max(ones, ones_here);
        }
        
        return (ones > zeroes);
    }
};
