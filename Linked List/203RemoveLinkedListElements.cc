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
    ListNode* removeElements(ListNode* head, int val) {
        // initialize a dummy head such that we no longer need to take care of case when the head node got deleted
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        // curr starts from dummy head, curr->next starts from actual head
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};