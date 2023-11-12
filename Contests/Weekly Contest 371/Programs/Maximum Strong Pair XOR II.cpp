class Solution 
{
    public:
    
    struct trie 
    {
        int frequency;
        trie *child[2];
        
        trie()
        {
            frequency = 0; 
            child[0] = child[1] = NULL;
        }
    };
    
    const int NO_OF_BITS = 20;
    
    int is_bit_set(int n, int bit)
    {
        return ( (n & (1 << bit)) != 0 );
    }
    
    void insert(trie *root, int n)
    {
        trie *current_node = root;
        current_node->frequency++;
        
        for(int bit = NO_OF_BITS; bit >= 0; bit--)
        {   
            int current_bit = (is_bit_set(n, bit) ? 1 : 0);

            if(current_node->child[current_bit] == nullptr)
            {
                current_node->child[current_bit] = new trie(); 
            }
            
            current_node = current_node->child[current_bit];
            current_node->frequency++;
        }
    }
    
    void erase(trie *root, int n)
    {
        trie *current_node = root;
        current_node->frequency--;
        
        for(int bit = NO_OF_BITS; bit >= 0; bit--)
        {
            int current_bit = (is_bit_set(n, bit) ? 1 : 0);
            
            current_node = current_node->child[current_bit];
            current_node->frequency--;
        }
    }
    
    int get_maximum_xor(trie *root, int n)
    {
        
        int maximum_xor = 0;
        trie *current_node = root;
        for(int bit = NO_OF_BITS; bit >= 0; bit--)
        {
            int same_bit = (is_bit_set(n, bit) ? 1 : 0);
            int other_bit = same_bit^1;

            if(current_node->child[other_bit] != nullptr && current_node->child[other_bit]->frequency > 0)
            {
                current_node = current_node->child[other_bit];
                maximum_xor |= (1 << bit);
            }
            else if(current_node->child[same_bit] != nullptr)
            {
                current_node = current_node->child[same_bit];
            }
            else 
            {
                return maximum_xor;
            }
        }
        
        return maximum_xor;
    }
    
    int maximumStrongPairXor(vector<int>& A) 
    {
        sort(A.begin(), A.end()); 
        
        trie * root = new trie();
        int answer = 0;
        for(int right = A.size() - 1, left = A.size() - 1; left >= 0; left--)
        {
            while(A[right] > 2*A[left])
            {
                erase(root, A[right]);
                right--;
            }
            
            insert(root, A[left]);
            int best_pair_for_here = get_maximum_xor(root, A[left]);
            //cout << "Best pair for " << A[left] << " is " << best_pair_for_here << "\n";
            
            answer = max(answer, best_pair_for_here);
        }
        
        return answer; 
    }
};
