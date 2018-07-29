#include <bits/stdc++.h>

using namespace std;

 struct ListNode
 {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution
{
    public:

    ListNode* middleNode(ListNode* head)
    {
        ListNode* tortoise = head, *rabbit = head;

        while(rabbit != NULL && rabbit->next != NULL)
        {
            tortoise = tortoise->next;
            rabbit = (rabbit->next)->next;
        }

        return tortoise;
    }
};
