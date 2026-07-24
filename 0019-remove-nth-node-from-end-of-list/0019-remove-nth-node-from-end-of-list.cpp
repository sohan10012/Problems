class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;

        ListNode* temp = head;

        while (temp) {
            length++;
            temp = temp->next;
        }

        if (length == n)
            return head->next;

        int pos = length - n;

        ListNode* curr = head;

        for (int i = 1; i < pos; i++)
            curr = curr->next;

        curr->next = curr->next->next;

        return head;
    }
};