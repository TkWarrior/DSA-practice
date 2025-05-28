class Solution {
public:
    bool isValid(string s) {
       unordered_map<char,char>umap = {{')','('},{'}','{'},{']','['}};
       stack<char>st;
       for(char ch:s){
            if(umap.find(ch)==umap.end()){
                st.push(ch);
            }
            else if(!st.empty() && umap[ch]==st.top()){
                st.pop();
            }
            else{
                return false;
            }
       }
       return st.empty();
    }
};