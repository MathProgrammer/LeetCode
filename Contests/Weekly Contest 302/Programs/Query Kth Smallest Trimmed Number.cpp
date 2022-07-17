

class Solution {
public:
      
    string trim(string S, int length)
    {
        string trimmed_S;
        for(int i = S.size() - length; i < S.size(); i++)
        {
            trimmed_S += S[i];
        }
        
        return trimmed_S;
    }
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        vector <int> answer(queries.size());
        for(int i = 0; i < queries.size(); i++)
        {
            vector <pair <string, int> > current_nums; 
            for(int j = 0; j < nums.size(); j++)
            {
                string trimmed_string = nums[j]; 
                
                current_nums.push_back(make_pair(trimmed_string, j));
            }
            
            int length = queries[i][1];
            
            struct sorted
            {
                int k; 

                sorted(int k)
                {
                    this->k = k;
                }

                bool operator()(const pair<string, int> &A, const pair<string, int> &B) const
                {
                    for(int i = A.first.size() - k; i < A.first.size(); i++)
                    {
                        if(A.first[i] < B.first[i])
                        {
                            return true;
                        }
                        else if(A.first[i] > B.first[i])
                        {
                            return false;
                        }
                    }

                    return (A.second < B.second);
                }
            };
            
            sort(current_nums.begin(), current_nums.end(), sorted(length));
            
            answer[i] = current_nums[queries[i][0] - 1].second;
        }
        
        return answer;
    }
};
