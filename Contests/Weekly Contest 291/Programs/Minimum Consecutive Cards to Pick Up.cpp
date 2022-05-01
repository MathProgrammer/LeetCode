class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        int answer = cards.size() + 1;
        map <int, int> last_occurence; 
        for(int i = 0; i < cards.size(); i++)
        {
            if(last_occurence[cards[i]] != 0)
            {
                answer = min(answer, i + 1 - last_occurence[cards[i]] + 1);
            }
            
            last_occurence[cards[i]] = i + 1;
        }
        
        return (answer > cards.size() ? -1 : answer);
    }
    
};
