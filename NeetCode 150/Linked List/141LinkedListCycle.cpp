/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // fast moves 2 steps at a time, slow moves 1 step at a time
        // if there is no cycle, fast and slow will NEVER meet
        if (head == NULL) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        if (fast->next == NULL) return false;
        fast = fast->next;
        while (fast != NULL & slow != NULL) {
            if (fast == slow) return true;
            if (fast->next == NULL) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
