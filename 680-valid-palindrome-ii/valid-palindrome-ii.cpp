class Solution {
public:
    bool checkPalindrome(int l , int r , string&s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0 ;
        int r = n-1;
      
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                return checkPalindrome(l+1 , r, s) || checkPalindrome(l , r-1, s);
            }
        }

        return true;
    }
};