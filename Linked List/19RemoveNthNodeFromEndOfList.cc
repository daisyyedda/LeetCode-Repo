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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        // fast pointer is n steps ahead of slow pointer
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        // when fast->next == nullptr, slow is the (n+1)th node from the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow->next is n-th node from the end
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        return dummyHead->next;
    }
};