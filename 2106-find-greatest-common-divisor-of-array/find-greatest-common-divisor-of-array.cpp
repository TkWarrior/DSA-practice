class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = INT_MIN ;
        int b = INT_MAX ;
        int n = nums.size();
        int temp = 0 ;
        
        for(int i = 0 ; i<n ;i++){
            a = max(a , nums[i]);
            b = min(b , nums[i]);
        }

        while(b!=0){
            temp = b ;
            b = a%b ;
            a = temp ;
        }

        return a ;
    }
};