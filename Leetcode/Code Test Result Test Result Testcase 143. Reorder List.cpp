class Solution {
public:
    void reorderList(ListNode* head) {
        if((!head) || (!head->next) || (!head->next->next)) return; 
        
        stack<ListNode*> stack;
        int size = 0;
        ListNode* ptr= head;
        while(ptr != NULL){
            stack.push(ptr);
            size++;
            ptr = ptr->next;
        }

        ListNode* pptr = head;
        for(int j=0 ; j<size/2 ; j++){
            ListNode *element = stack.top();
            stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
    pptr->next = NULL;
    }
};
