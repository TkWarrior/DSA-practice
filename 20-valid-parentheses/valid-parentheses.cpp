class Solution {
public:
    bool isValid(string s) {
        unordered_map<char ,char>umap = { {')','('} , {']','['},{'}','{'} };
        stack<char>st;
        
        for(char c:s){
            if(umap.find(c)==umap.end()){
                st.push(c);
            }

            else if(!st.empty() && umap[c]==st.top()){
                st.pop();
            }
            else{
                return false;
            }
           
        }

       return st.empty();
    }
};