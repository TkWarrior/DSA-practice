class Solution {
public:
    int strStr(string haystack, string needle) {
        //point is to store the value whenever first time the needle character matchs with the haystack and store it in some variable 
        int i = 0;
        int j = 0;
        
        
        while(i<haystack.length() && j<needle.length()){
            if((haystack[i] == needle[j])){
                
                j++;
            }
            else{
                i = i-j;
                j=0;
                
            }
            i++;
        }
       
       if(j == needle.length()){
            return i-needle.length();
       }
        
        return -1;
    }
};