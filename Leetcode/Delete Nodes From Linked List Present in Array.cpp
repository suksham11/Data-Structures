class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuetoremove(nums.begin() , nums.end());
        while(head != nullptr && valuetoremove.count(head->val) > 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if(head == nullptr){
            return nullptr;
        }
        ListNode* current = head;
        while(current->next != nullptr){
            if(valuetoremove.contains(current->next->val)){
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};
