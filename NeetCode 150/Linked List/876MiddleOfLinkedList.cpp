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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        // the two pointers approach
        // fast moves twice as fast as slow
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            if (fast->next == NULL) return slow;
            if (fast->next->next == NULL) return slow->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};