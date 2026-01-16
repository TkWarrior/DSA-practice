class Solution {
public:
    bool isPalindrome(int l , int r , string s){
       
        while(l<r){
            if(s[l]!=s[r]){
               return false ;
            }
            l++;
            r--;
        }

        return true ;

    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0 ; 
        int r = n-1 ; 

        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{ // if mismatch we just need to figure which one character should we delete so that the string becomes palindrome
                return isPalindrome(l+1 , r, s) || isPalindrome(l ,r-1, s);
            }
        }

        return true;
    }
};