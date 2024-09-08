class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        int size = 0;
        ListNode* current = head;
        while(current != nullptr){
            size++;
            current = current->next;
        }
        int splitsize = size/k;
        int numremainingparts = size%k;
        current = head;
        for(int i=0 ; i<k ; i++){
            ListNode newpart(0);
            ListNode* tail = &newpart;

            int currentsize = splitsize;
            if(numremainingparts > 0){
                numremainingparts--;
                currentsize++;
            }
            for(int j=0 ; j<currentsize ; j++){
                tail->next = new ListNode(current->val);
                tail = tail->next;
                current = current->next;
            }
            ans[i] = newpart.next;
        }
        return ans;
    }
};
