class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];

        string substr = "";
        if(strs.size()==1){
            return s;
        }
        for(int i = 1 ; i<strs.size() ; i++){
            
            substr = "";
            for(int j = 0 ;j<s.length() ; j++){
                if(s[j]==strs[i][j]){
                    substr = substr+ s[j];
                }
               else{
                 break;
               }
            }
            s = substr;
        }
        return s;
    }
};