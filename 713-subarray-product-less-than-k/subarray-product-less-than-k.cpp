class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int c = 0 ;
        int prod = 1;
        int i = 0 ; 
        int j = 0 ;
        int n = nums.size();
        
        if(k==0) return 0 ;
       
        while(j<n){
            prod = prod*nums[j]; 
           
            while(prod>=k){
                prod = prod/nums[i];
                i++;
            }
            c += j-i+1;
            j++;
        }

        return c ;
    }
};