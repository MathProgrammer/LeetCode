class Solution {
public:
    
    struct Event 
    {
        int time, index, type; 
        
        Event(){}
        
        Event(int T, int Type)
        {
            time = T; type = Type;
        }
        
        Event(int T,  int Type, int Index)
        {
            index = Index; 
            time = T; 
            type = Type;
        }
        
        int operator<(const Event&P)
        {
            if(time == P.time)
            {
                return (type < P.type);
            }
            
            return (time < P.time);
        }
    };
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        const int BEGINNING = 0, ENDING = 1, PERSON = 2;
        vector <Event> events;    
        for(int i = 0; i < flowers.size(); i++)
        {
            events.push_back(Event(flowers[i][0], BEGINNING));
            events.push_back(Event(flowers[i][1] + 1, ENDING));
        }
        
        for(int i = 0; i < persons.size(); i++)
        {
            events.push_back(Event(persons[i], PERSON, i));
        }
        
        sort(events.begin(), events.end());
        
        int segment_start = 0, segment_end = 0;
        vector <int> open_segments(persons.size());
        for(int i = 0; i < events.size(); i++)
        {
            switch(events[i].type)
            {
                case BEGINNING : segment_start++; 
                                 break;
                
                case ENDING : segment_end++; 
                              break;
                    
                case PERSON : open_segments[events[i].index] = segment_start - segment_end;
            }
        }
        
        return open_segments;
    }
};
