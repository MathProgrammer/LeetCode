class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer; 
        for(int i = 0, j = 0; i < s.size(); i++)
        {
            if(j < spaces.size() && i == spaces[j])
            {
                answer += " ";
                j++;
            }
            
            answer += s[i];
        }
        
        return answer;
    }
};
