class Solution {
public:
void solve(ListNode* &slow,  ListNode* &fast){
    if(fast == NULL) {
        return;
    }
    if(fast->next == NULL){
        return;
    }

    slow = slow->next;
    fast = fast->next;
    fast = fast->next;
    solve(slow , fast);
}


    ListNode* middleNode(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;
    solve(slow , fast);
    return slow;
    }
};
