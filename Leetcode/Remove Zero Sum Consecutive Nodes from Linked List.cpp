class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* start = front;

        while(start != NULL){
            int prefixsum = 0;
            ListNode* end = start->next;

            while(end != NULL){
                prefixsum += end->val;
                
                if(prefixsum == 0){
                    start->next = end->next;
                }
                end = end->next;
            }
        start = start->next;
        }
    return front->next;
    }
};
