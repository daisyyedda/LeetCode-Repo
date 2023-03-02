class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;
   
    MyStack() {
        
    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        int res = queue1.front();
        queue1.pop();
        while (!queue1.empty()) {
            queue2.push(res);
            res = queue1.front();
            queue1.pop();    
        }
        queue1 = queue2;
        while (!queue2.empty()) queue2.pop();
        return res;
    }
    
    int top() {
        return queue1.back();
    }
    
    bool empty() {
        if (!queue1.empty()) cout << queue1.front();
        return queue1.empty();
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