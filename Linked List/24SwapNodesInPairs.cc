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
    ListNode* swapPairs(ListNode* head) {
        // create a dummyHead that points to head
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* tmp1 = curr->next;
            ListNode* tmp2 = curr->next->next->next;
            curr->next = tmp1->next;
            curr->next->next = tmp1;
            tmp1->next = tmp2;
            curr = curr->next->next;    
        }
        return dummyHead->next;
    }
};