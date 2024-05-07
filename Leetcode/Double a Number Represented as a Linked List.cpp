class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        pair<int, ListNode*> result = func(head);
        if (result.first!=0){
            ListNode* new_head = new ListNode(result.first);
            new_head->next = result.second;
            return new_head;
        }
        return result.second;
    }

    private: 
       pair<int, ListNode*> func(ListNode* head){
        int a = head->val * 2;
        if(head->next){
            pair<int, ListNode*> next_result = func(head->next);
            a += next_result.first;
        }
    
        head->val = a%10;
        return  {a/10 , head};
       }
       
};
