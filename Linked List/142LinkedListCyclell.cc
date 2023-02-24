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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;   

        while (fast != NULL && fast->next != NULL) {
          // fast moves 2 steps, slow moves 1 step, relative speed is 1
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
          // distance from head to cycle start == distance from the meeting point to the cycle start
                ListNode* start = head;
                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        } 
        return NULL;
    }
};