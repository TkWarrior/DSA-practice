class Solution {
public:
    int maxPower(string s) {
        int i = 0 ; 
        int j = 1 ; 
        int max_p = 1 ;

        while(j<s.size()){
            if(s[i]!=s[j]){
                i = j ;
            }else{
                max_p = max(max_p , j-i+1);      
            }
            j++;
            
        }

        return max_p;
    }
};