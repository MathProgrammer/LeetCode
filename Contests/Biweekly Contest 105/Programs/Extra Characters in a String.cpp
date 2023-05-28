class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        set <string> D; 
        for(string word : dictionary)
        {
            D.insert(word);
        }
        
        vector <int> minimum_left_over(s.size());
        for(int i = 0; i < s.size(); i++)
        {
            string current; 
            minimum_left_over[i] = i + 1;
            
            for(int j = i; j >= 0; j--)
            {
                current = s[j] + current; 
                
                int left_over_here = (j > 0 ? minimum_left_over[j - 1] : 0);
                
                if(D.count(current) == 0)
                {
                    left_over_here += current.size();
                }
                
                minimum_left_over[i] = min(minimum_left_over[i], left_over_here);
            }
        }
        
        return minimum_left_over[s.size() - 1];
    }
};
