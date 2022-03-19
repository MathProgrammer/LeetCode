class Solution {
public:
    
    int min(int x, int y)
    {
        return (x < y ? x : y);
    }
    
    int minimumWhiteTiles(string floor, int num_carpets, int carpet_len) 
    {
        const int oo = 1e9;
        const char WHITE = '1';
        vector <vector <int> > minimum_tiles(floor.size(), vector <int> (num_carpets + 1, oo));
        for(int i = 0; i < floor.size(); i++)
        {
            minimum_tiles[i][0] = (floor[i] == WHITE);
            
            if(i > 0)
            {
                minimum_tiles[i][0] += minimum_tiles[i - 1][0];
            }
            
        }
        
        for(int i = 0; i < floor.size(); i++)
        {
            for(int c  = 1; c <= num_carpets; c++)
            {
                if(carpet_len*c>= i + 1)
                {
                    minimum_tiles[i][c] = 0; 
                    continue;
                }
                
                minimum_tiles[i][c] = minimum_tiles[i - carpet_len][c - 1];
                
                if(i > 0)
                {
                    minimum_tiles[i][c] = min(minimum_tiles[i][c], minimum_tiles[i - 1][c] + (floor[i] == WHITE));
                }
                
            }
        }   
    
        return minimum_tiles[floor.size() - 1][num_carpets];
    }
};
