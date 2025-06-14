class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //this question is similar to next greater element problem 
        // first i will teaverse the array from the last 
        // then i will store the indexes of next greater element in the stack

        int n = temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = st.top() - i;
            }

            st.push(i);
        }
        return ans;
    }
};