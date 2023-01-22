class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int frequency_1 = 0;
        int frequency_11 = 0, frequency_01 = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                frequency_1++;
            }
            
            if(s[i] == '1' && target[i] == '1')
            {
                frequency_11++;
            }
            
            if(s[i] == '0' && target[i] == '1')
            {
                frequency_01++;
            }
        }
        
        if(s == target)
        {
            return true;
        }
        
        if(frequency_1 == 0)
        {
            return false;
        }
        
        if(frequency_11 > 0)
        {
            return true;
        }
        
        if(frequency_01 > 0)
        {
            return true;
        }
        
        return false;
    }
};
