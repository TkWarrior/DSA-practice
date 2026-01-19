class Solution {
public:
    bool isValid(string s) {
        stack<int>st ;
        unordered_map<char , char>mp = {{')','('},{']','['},{'}','{'}};
        
        for(char&ch : s){
            if(st.empty()){
                st.push(ch);
            }
            else if(!st.empty() && mp[ch]==st.top()){
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