class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* temp = insertGreatestCommonDivisors(head->next);
        ListNode* gcdnode = new ListNode(__gcd(head->val , head->next->val));
        gcdnode->next = temp;
        head->next = gcdnode;

        return head;
    }
};
