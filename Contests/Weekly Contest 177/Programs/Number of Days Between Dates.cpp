class Solution
{
    public:
    
    int is_leap_year(int y)
    {
        if(y%400 == 0)
        {
            return true;
        }
        
        if(y%100 == 0)
        {
            return false;
        }
        
        return (y%4 == 0);
    }
    
    int no_of_leap_years(int y)
    {
        return (y/4 - y/100 + y/400);
    }
    
    int no_of_days(string date)
    {
        int year = 0;
        
        for(int i = 0; i <= 3; i++)
        {
            year= year*10 + (date[i] - '0');
        }
        
        int month = 0;
        
        for(int i = 5; i <= 6; i++)
        {
            month = month*10 + (date[i] - '0');
        }
        
        int day = 0;
        
        for(int i = 8; i <= 9; i++)
        {
            day = day*10 + (date[i] - '0');
        }
        
        int days_count = (year - 1)*365 + no_of_leap_years(year - 1);
        for(int i = 1; i < month; i++)
        {
            switch(i)
            {
                case 1 :
                case 3 :
                case 5 :
                case 7 :
                case 8 :
                case 10 :
                case 12 : days_count += 31;
                          break;
                    
                case 4 :
                case 6 :
                case 9 :
                case 11 : days_count += 30;
                          break;
                    
                case 2 : days_count += (is_leap_year(year) ? 29 : 28);
                         break;
              }
        }
        
        days_count += day;
        
        return days_count;
    }
    
    int daysBetweenDates(string date1, string date2)
    {
        return abs(no_of_days(date1) - no_of_days(date2));
    }
};
