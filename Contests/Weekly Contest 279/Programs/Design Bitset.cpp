class Bitset {
public:
    
    string S;
    int sum, flips;
    
    Bitset(int size) 
    {
        for(int i = 0; i < size; i++)
        {
            S += (char)('0');
        }
        
        sum = 0;
        flips = 0;
    }
    
    void fix(int idx) 
    {
        if(S[idx] == '0' && flips == 0)
        {
            S[idx] = '1';
            sum++;
        }
        
        if(S[idx] == '1' && flips == 1)
        {
            S[idx] = '0';
            sum++;
        }
        
        //cout << "Sum = " << sum << "\n";
    }
    
    void unfix(int idx) 
    {
        if(S[idx] == '1' && flips == 0)
        {
            S[idx] = '0';
            sum--;
        }   
        
        if(S[idx] == '0' && flips == 1)
        {
            S[idx] = '1';
            sum--;
        }
        
         //cout << "Unfix " << idx << " Sum = " << sum << "\n";
    }
    
    void flip() 
    {
         flips++;
         flips %= 2;
        
         sum = (S.size() - sum); //cout << "Sum = " << sum << "\n";
    }
    
    bool all() 
    {
        //cout << "Flips = " << flips << " Sum = " << sum << "\n";
        return (sum == S.size());
    }
    
    bool one() 
    {
        return (sum > 0);
    }
    
    int count() 
    {
        return sum;
    }
    
    string toString() 
    {
        if(flips == 0)
        {
            return S;
        }
        
        for(int i = 0; i < S.size(); i++)
        {
            switch(S[i])
            {
                case '1': S[i] = '0'; break;
                case '0': S[i] = '1'; break;
            }
        }
        flips = 0;
        
        return S;
    }
};
