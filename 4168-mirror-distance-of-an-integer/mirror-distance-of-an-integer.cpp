class Solution {
public:
    int mirrorDistance(int n) {
        int rev_n = 0 ;
        int rem = 0 ;
        int old_n = n ;

        while(n>0){    
            rem = n%10;
            rev_n = rev_n*10 + rem ;      
            n = n/10 ;
        }
        n = old_n ;
        return abs(n - rev_n);
    }
};