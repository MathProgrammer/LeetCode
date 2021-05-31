class Solution {
public:
    
    int sum(string &S)
    {
        int value = 0;
        
        for(char ch : S)
        {
            value = value*10 + (ch - 'a');
        }
        
        return value;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        return ( sum(firstWord) + sum(secondWord) == sum(targetWord) );
    }
};
