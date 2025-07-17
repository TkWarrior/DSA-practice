class Solution {
public:
     const int MODE = 1e9 + 7;
    long long findPower(long long a , long long b){
       
        if(b==0){
            return 1;
        }
        long long half = findPower(a , b/2);
        long long result = (half*half)%MODE;
        if(b%2==1){
            return result = (result*a)%MODE;
        }

        return result%MODE;
    }

    int countGoodNumbers(long long n) {

        // Brute force Approach But will give TLE - TC-O(n)
        // const int MOD = 1e9 + 7;
        // long long prod = 1 ; 

        // for(int i = 0 ; i<n ; i++){
        //     if(i%2 == 0){
        //         prod = (prod*5)%MOD;
        //     }
        //     else{
        //         prod = (prod*4)%MOD;
        //     }
        // }
        
        // return (prod)%MOD;

        // Optimised Approach - recursive approach - O(log n)

        return (findPower(5 , (n+1)/2) * findPower(4 , n/2))%MODE;

        
    }
};