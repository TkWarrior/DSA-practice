class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_s = 1;
        int n = nums.size();
        int c = 1 ; 
        if(n==1) return 1 ;

        for(int i = 0 ; i<n-1 ; i++){
            if(nums[i]<nums[i+1]){
                c++;
                max_s = max(max_s , c);
            }else{
                
                c = 1 ;
            }
        }

        return max_s ;

       
    }
};