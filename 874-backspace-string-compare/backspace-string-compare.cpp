class Solution {
public:
    string makestring(string &str){
        stack<char>st;
        for(char ch:str){
            if(ch == '#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }
           
        string result = "";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
    
    bool backspaceCompare(string s, string t) {
       return  makestring(s) == makestring(t);
    }
};