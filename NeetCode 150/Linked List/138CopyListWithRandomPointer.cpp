/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// we use an iterative approach
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;
        Node* h = head;
        // first pass: copy the nodes
        while (h) {
            hash[h] = new Node(h->val);
            h = h->next;
        }
        h = head;
        // second pass: copy the pointers
        while (h) {
            Node* tmp = hash[h];
            tmp->next = hash[h->next];
            tmp->random = hash[h->random];
            h = h->next;
        }
        return hash[head];
    }
};