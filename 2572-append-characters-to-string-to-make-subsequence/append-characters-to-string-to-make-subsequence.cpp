class Solution {
public:
    int appendCharacters(string s, string t) {
        // if already t subsequence of s return 0
        int i = 0 ;
        int j = 0 ;
        int m = s.size();
        int n = t.size();
        while(i<m && j<n+1){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }

        if(j==n){
            return 0 ;
        }
        
        while(i<m && j<n){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                break ;
            }
        }

        return n-j;

    }
};