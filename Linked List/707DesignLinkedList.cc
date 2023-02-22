class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };  

    MyLinkedList() {
        dummyHead = new LinkedNode(0); 
        size = 0;
    }
    
    int get(int index) {
        LinkedNode* curr = dummyHead->next;
        if (index >= 0 && index < size) {
            while (index--) {
                curr = curr->next;
            }
            return curr->val;
        } else {
            return -1;
        }
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curr = dummyHead;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= size) {
            LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* curr = dummyHead;
            while(index--) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            size++;
        }   
    }
    
    void deleteAtIndex(int index) {
        if (index < size && index >= 0) {
            LinkedNode* curr = dummyHead;
            while(index--) {
                curr = curr->next;
            }
            LinkedNode* tmp = curr->next;
            curr->next = tmp->next;
            delete tmp;
            size--;
        }   
    }
    private:
        int size;
        LinkedNode* dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */