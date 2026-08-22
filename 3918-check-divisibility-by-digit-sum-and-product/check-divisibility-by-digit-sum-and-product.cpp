class Solution {
public:
    bool checkDivisibility(int n) {
        int dig_sum = 0 ;
        int prod = 1;
        int original = n ;

        while(n!=0){
            int rem = n%10 ;
            dig_sum += rem;
            prod *= rem; 
            n = n/10;
        }
        cout<<dig_sum<<endl;
        cout<<prod<<endl;
       
        if(original % (dig_sum + prod) == 0){
            return true;
        }

        return false;
    }
};