class MinStack {
public:
    vector<int> stack1 = {};
    vector<int> min_stack = {};
    int currentMin;
    MinStack() {
        
    }
    
    void push(int val) {
        if (min_stack.empty() || val <= min_stack.back()) {
            min_stack.push_back(val);
        }
        stack1.push_back(val);
    }
    
    void pop() {
        if(stack1.back() == min_stack.back())
        {
            min_stack.pop_back();
        }
        stack1.pop_back();
    }
    
    int top() {
        int end_index = stack1.size() - 1;
        return stack1.back();
    }
    
    int getMin() {
        int min_stack_end_val = min_stack[(min_stack.size() - 1)];
        return min_stack.back();
    }
};
