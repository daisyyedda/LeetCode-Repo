class MyStack {
public:
    queue<int> stIn;
    queue<int> stOut;

    // initialize an empty stack
    MyStack() {
        
    }
    
    // push to the top of the stack
    void push(int x) {
        stIn.push(x);
    }
    
    // remove and return the element on top of stack
    int pop() {
        int size = stIn.size();
        size--;
        while (size--) { 
            stOut.push(stIn.front());
            stIn.pop();
        }
        int result = stIn.front(); 
        stIn.pop();
        stIn = stOut;           
        while (!stOut.empty()) {
            stOut.pop();
        }
        return result;   
    }
    
    // return the element on top of the stack
    int top() {
        return stIn.back();
    }
    
    // check whether the stack is empty
    bool empty() {
        return stIn.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */