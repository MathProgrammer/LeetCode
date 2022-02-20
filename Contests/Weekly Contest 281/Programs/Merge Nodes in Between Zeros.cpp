class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* current = head->next;
        ListNode* lastzero = head;
        while(current != NULL)
        {
            if(current->val != 0)
            {
                lastzero->val += current->val;
            }
            else if(current->val == 0)
            {
                if(current->next == NULL)
                {
                    lastzero->next = current->next; 
                }
                else 
                {
                    lastzero->next = current;
                    lastzero = current;
                }
            }
            
            current = current->next;
        }   
        
        return head;
    }
};
