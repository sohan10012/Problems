/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right ){
            return head;
        }        

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* bleft = dummy;

        for(int i = 1 ; i < left ; i++){
            bleft = bleft->next;
        }

        ListNode* cur = bleft->next;
        ListNode* prev = NULL;

        for(int i = 0 ; i < right - left + 1 ; i++){
            ListNode* nexts = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nexts;
        }

        ListNode* leftNode = bleft->next;
        bleft->next = prev;
        leftNode->next = cur;

        return dummy->next;
    }
};