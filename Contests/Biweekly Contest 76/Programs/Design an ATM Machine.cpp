class ATM {
public:
    
    const int NO_OF_DENOMINATIONS = 5;
    vector <long long> values;
    vector <long long> frequency;
    
    ATM() 
    {
        values.resize(NO_OF_DENOMINATIONS);
        frequency.resize(NO_OF_DENOMINATIONS);
        
        values = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) 
    {
        for(int i = 0; i < banknotesCount.size(); i++)
        {
            frequency[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) 
    {
        vector <int> money(NO_OF_DENOMINATIONS);
        for(int i = NO_OF_DENOMINATIONS - 1; i >= 0; i--)
        {
            long long notes = min(frequency[i], amount/values[i]);
            
            amount -= notes*values[i];
        
            money[i] += notes;
        }
        //cout << "Total = " << total << "\n";
        
        if(amount != 0)
        {
            vector <int> NOT_POSSIBLE(1, -1);
            return NOT_POSSIBLE;
        }
        
        for(int i = 0; i < NO_OF_DENOMINATIONS; i++)
        {
            frequency[i] -= money[i];
        }
        
        return money;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
