class MinStack {
    stack<int>storeAll , storeMin;
public:
    MinStack() {
       
    }
    
    void push(int val) {
       storeAll.push(val);
       if(storeMin.empty() || val<=storeMin.top()) storeMin.push(val);
    }
    
    void pop() {
        if(storeMin.top()==storeAll.top()) storeMin.pop();
        storeAll.pop();  
    }
    
    int top() {
        if(storeAll.empty()){
            return -1;
        }else{
            return storeAll.top();
        }   
    }
    
    int getMin() {
        if(storeMin.empty()){
            return -1;
        }else{
            return storeMin.top();
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */