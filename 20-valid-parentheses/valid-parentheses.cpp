class Solution {
public:
    bool isValid(string s) {
        stack<int>st ;
        unordered_map<int,int>mp = { {')','('} , {'}' , '{'} , {']','['}};

        for(char&ch : s){
            if(st.empty()){
                st.push(ch);
            }
            else if(!st.empty() && st.top()==mp[ch]){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        if(st.empty()){
            return true;
        }

        return false;
    }
};