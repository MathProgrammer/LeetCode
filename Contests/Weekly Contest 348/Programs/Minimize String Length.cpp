class Solution {
public:
    int minimizedStringLength(string S) {
        set <char> distinct; 
        for(char ch : S)
        {
            distinct.insert(ch);
        }
        
        return distinct.size();
    }
};
