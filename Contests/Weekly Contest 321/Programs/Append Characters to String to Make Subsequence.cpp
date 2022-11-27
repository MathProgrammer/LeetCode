class Solution {
public:
    int appendCharacters(string s, string t) {
        int need_to_add = t.size();
        
        for(int i = 0, j = 0; i < s.size() && j < t.size(); i++)
        {
            if(s[i] == t[j])
            {
                j++;
                need_to_add--;
            }
        }
        
        return need_to_add;
    }
};
