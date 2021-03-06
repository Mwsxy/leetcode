#include "header.h"
#include <algorithm>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        inp = {};
        out = {};
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inp.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty()) trans();
        int ret = out.top();
        out.pop();
        return ret;
    
    }
    
    /** Get the front element. */
    int peek() {
        if (out.empty()) trans();
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inp.empty() && out.empty();
    }
private:
    stack<int> inp,out;
    void trans() {
        while (!inp.empty()) {
            out.push(inp.top());
            inp.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 int main() {
     return 0;
 }