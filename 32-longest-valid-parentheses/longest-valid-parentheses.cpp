class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st ;
        st.push(-1);
        int res = 0 ;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty() ){
                    st.push(i);
                }else{
                    res = max(res , i - st.top()); 
                }
            }
        }
        return res ;
        // int count = 0 ;
        // unordered_map<char,char>umap = {{')','('}};
        // stack<char>st ;

        // for(int i = 1 ; i<s.length() ; i++){
        //     st.push(s[i-1]);
        //     if(!st.empty() && s[i]==')' && st.top() == '(' ){
        //         count +=2 ; 
        //         st.pop();
        //     }
        // }

        // return count ;
    }
};