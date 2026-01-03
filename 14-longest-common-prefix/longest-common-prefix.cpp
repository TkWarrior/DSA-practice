class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string match = strs[0];
        int n = strs.size() ;
        string res = "";
        if(n==1) return match ;
        for(int i = 1 ; i<n ; i++){
            res = "";
            for(int j = 0 ; j<strs[i].size() ; j++){
                if(match[j] == strs[i][j]){
                    res += match[j];
                }else{
                    break;
                }
            }
            
            match = res ;
        }

        return res ;
    }
};