class Solution {
public:
    int reverse(int x) {
        int n = 0 ;
        int rem = 0 ;

        // while(abs(x)>0){
        //     n++;
        //     x = x/10;
        // }

        int rev = 0;
        while(x!=0){
            rem = x%10;
             x = x/10; 
            
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8)) return 0;
            rev = rev*10 + rem ;
        }
        cout<<rev;
        return rev;
    }
};