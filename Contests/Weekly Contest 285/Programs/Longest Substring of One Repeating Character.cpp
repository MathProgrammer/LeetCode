struct Node 
{
    int prefix, suffix, answer;
    
    Node()
    {
    
    }
};

const int MAX_N = 1e5 + 15, NO_OF_ALPHABETS = 26;
Node tree[3*MAX_N][NO_OF_ALPHABETS];

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)

class Solution 
{
    public:
    
    void merge(Node &Parent, Node &L, int left_1, int right_1, Node &R, int left_2, int right_2)
    {
        Parent.prefix = L.prefix;
        if(L.prefix == right_1 - left_1 + 1)
        {
            Parent.prefix += R.prefix;
        }
        
        Parent.suffix = R.suffix;
        if(R.suffix == right_2 - left_2 + 1)
        {
            Parent.suffix += L.suffix;
        }
        
        Parent.answer = max(L.answer, R.answer);
        Parent.answer = max(Parent.answer, L.suffix + R.prefix);
    }
    
    void build(int alpha, int n, int left, int right)
    {
        if(left == right)
        {
            tree[n][alpha].answer = tree[n][alpha].prefix = tree[n][alpha].suffix = 0;
            return;
        }
        
        int mid = (left + right)/2;
        build(alpha, LEFT(n), left, mid);
        build(alpha, RIGHT(n), mid + 1, right);
        
        merge(tree[n][alpha], tree[LEFT(n)][alpha], left, mid, tree[RIGHT(n)][alpha], mid + 1, right);
    }
    
    void update(int alpha, int n, int left, int right, int position, int value)
    {
        if(right < position || position < left)
        {
            return;
        }
        
        if(left == right)
        {
            tree[n][alpha].prefix =  tree[n][alpha].suffix =  tree[n][alpha].answer = value;
            
            return;
        }
        
        int mid = (left + right)/2;
        update(alpha, LEFT(n), left, mid, position, value);
        update(alpha, RIGHT(n), mid + 1, right, position, value);
        
        merge(tree[n][alpha], tree[LEFT(n)][alpha], left, mid, tree[RIGHT(n)][alpha], mid + 1, right);
    }
    
    vector<int> longestRepeating(string S, string queryCharacters, vector<int>& queryIndices) 
    {
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            build(alpha, 1, 0, S.size() - 1);
        }
        
        for(int i = 0; i < S.size(); i++)
        {
            update(S[i] - 'a', 1, 0, S.size() - 1, i, 1);
        }
        
        vector <int> answer;
        for(int i = 0; i < queryIndices.size(); i++)
        {
            update(S[queryIndices[i]] - 'a', 1, 0, S.size() - 1, queryIndices[i], 0); 
            
            update(queryCharacters[i] - 'a', 1, 0, S.size() - 1, queryIndices[i], 1);
            
            S[queryIndices[i]] = queryCharacters[i];
            
            int answer_here = 0;
            for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
            {
                answer_here = max(answer_here, tree[1][alpha].answer);
            }
            answer.push_back(answer_here);
        }
        
        return answer;
    }
};
