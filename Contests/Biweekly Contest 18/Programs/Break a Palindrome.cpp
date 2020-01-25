#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution
{
    string breakPalindrome(string palindrome)
    {
        if(palindrome.size() == 1)
        {
            string empty;
            return empty;
        }
        
        int n = palindrome.size();
        
        for(int i = 0; i < palindrome.size(); i++)
        {
            if(palindrome[i] != 'a' && !(palindrome.size()%2 == 1 && i == palindrome.size()/2))
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[palindrome.size() - 1] = 'b';
                
        return palindrome;
    }
};
