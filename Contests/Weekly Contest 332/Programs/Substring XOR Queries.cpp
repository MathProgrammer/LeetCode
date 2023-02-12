class Solution {
public:
    
    int bit_count(int n)
    {
        int count = 0;
        
        if(n == 0)
        {
            count = 1;
            return count;
        }
        
        while(n > 0)
        {
            count++;
            
            n = n/2;
        }
        
        return count;
    }
    
    vector<vector<int>> substringXorQueries(string S, vector<vector<int>>& queries) {
        
        map <int, int> earliest_occurence;
        for(int i = 0; i < S.size(); i++)
        {
            const int MAX_BITS = 31;
            int current_value = 0;
            
            if(S[i] == '0')
            {
                if(earliest_occurence.find(0) == earliest_occurence.end())
                {
                    earliest_occurence[0] = i;
                }
                continue;
            }
            
            for(int bit = 0; bit < MAX_BITS && i + bit < S.size(); bit++)
            {
                current_value = (current_value << 1) + (S[i + bit] - '0');
                
                if(earliest_occurence.find(current_value) == earliest_occurence.end())
                {
                    earliest_occurence[current_value] = i;
                }
                else
                {
                    earliest_occurence[current_value] = min(earliest_occurence[current_value], i);
                }
            }
        }
        
        vector <vector <int> > answer; 
        for(int i = 0; i < queries.size(); i++)
        {
            int current_value = queries[i][0]^queries[i][1];
            vector <int> current_answer(2, -1);
            
            if(earliest_occurence.find(current_value) != earliest_occurence.end())
            {
                current_answer[0] = earliest_occurence[current_value];
                current_answer[1] = current_answer[0] + bit_count(current_value) - 1;
            }
            
            answer.push_back(current_answer);
        }
        
        return answer;
    }
};
