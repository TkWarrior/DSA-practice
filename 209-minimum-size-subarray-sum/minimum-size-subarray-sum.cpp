class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0 ;
        int r = 0;
        int sum = 0;
        int n = nums.size();
        int min_length = n;
       
        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
        }
        if(sum<target){
            return 0;
        }
        else{
            sum = 0;
            while(r<n){
           
            sum = sum+nums[r];
            
            while(sum>=target){
                sum = sum-nums[l];
                min_length = min(min_length,r-l+1);
                l++;
            }
            r++;
        }
        }
        
       
        return min_length;
    }
};