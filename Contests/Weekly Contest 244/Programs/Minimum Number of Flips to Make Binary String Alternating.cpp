class Solution 
{
    public:
    int minFlips(string s) 
    {
        const int FIRST_ZERO = 0, FIRST_ONE = 1;
        vector < vector <int> > prefix_flips(s.size(), vector <int> (2, 0));
        prefix_flips[0][FIRST_ZERO] = (s[0] != '0');
        prefix_flips[0][FIRST_ONE] = (s[0] != '1');
        for(int i = 1; i < s.size(); i++)
        {
            prefix_flips[i][FIRST_ZERO] = (s[i] != (i)%2 + '0') + prefix_flips[i - 1][FIRST_ZERO];
            prefix_flips[i][FIRST_ONE] = (s[i] != (i + 1)%2 + '0') + prefix_flips[i - 1][FIRST_ONE];
        }
        
        vector < vector <int> > suffix_flips(s.size(), vector <int> (2, 0));
        suffix_flips[s.size() - 1][FIRST_ZERO] = (s.back() != '0');
        suffix_flips[s.size() - 1][FIRST_ONE] = (s.back() != '1');
        for(int i = s.size() - 2; i >= 0; i--)
        {
            suffix_flips[i][FIRST_ZERO] = (s[i] != '0') + suffix_flips[i + 1][FIRST_ONE];
            suffix_flips[i][FIRST_ONE] = (s[i] != '1') + suffix_flips[i + 1][FIRST_ZERO];
        }
        
        int minimum_flips = min(prefix_flips[s.size() - 1][FIRST_ZERO], prefix_flips[s.size() - 1][FIRST_ONE]);
        for(int i = 1; i < s.size(); i++)
        {
            int choice_zero = suffix_flips[i][FIRST_ZERO] + (i%2 == s.size()%2 ? 
                                                             prefix_flips[i - 1][FIRST_ZERO] : prefix_flips[i - 1][FIRST_ONE]);
            int choice_one = suffix_flips[i][FIRST_ONE] + (i%2 == s.size()%2 ? 
                                                          prefix_flips[i - 1][FIRST_ONE] : prefix_flips[i - 1][FIRST_ZERO]);
            
            minimum_flips = min(minimum_flips, min(choice_zero, choice_one));
        }
        
        return minimum_flips;
    }
};
