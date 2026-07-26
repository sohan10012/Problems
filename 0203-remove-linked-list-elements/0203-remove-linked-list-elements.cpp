class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* cur = dummy;

        while(cur->next != NULL){

            if(cur->next->val == val){
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete(temp);
            }
            else{
                cur = cur->next;
            }
            
        }

        return dummy->next;
        
    }
};