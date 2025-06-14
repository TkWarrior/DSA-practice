class StockSpanner {
public:
    stack<pair<int,int>>st ;// stack pair of {price , span}
    StockSpanner() {
      
    }
    
    int next(int price) {
        
       int span = 1;
        // if the price at the top of the stack is lesser than the next element then ot will be popped out
       while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
       }

       st.push({price , span});   
       
       return span;
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */