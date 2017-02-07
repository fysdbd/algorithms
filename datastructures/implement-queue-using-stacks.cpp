
/*
    Implement Queue using Stacks

    Implement the following operations of a queue using stacks.
    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.
    Notes:
    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() { }

    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
        if (data.size() == 1) { first_element = data.top(); }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> newdata;
        while (!data.empty()) {
            newdata.push(data.top());
            data.pop();
        }
        int result = newdata.top();
        newdata.pop();
        if (newdata.size() > 0) { first_element = newdata.top(); }
        while (!newdata.empty()) {
            data.push(newdata.top());
            newdata.pop();
        }
        return result;
    }

    /** Get the front element. */
    int peek() {
        return first_element;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
private:
    stack<int> data;
    int first_element;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
 
