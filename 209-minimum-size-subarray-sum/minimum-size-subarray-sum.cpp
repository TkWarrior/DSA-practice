class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        int j = 0 ;
        int mini = n ;
        int s = 0 ;
        
        for(int i = 0 ; i<n ; i++){
            s += nums[i];
        }
       
        if(s<target) return 0 ;

        s = 0 ;
        
        while(j<n){
             s += nums[j];
            while(s>=target){ 
                mini = min(mini , j-i+1); 
                 s -= nums[i];         
                i++;
            }
           
            j++;
        }
        
        // if(s<target){
        //     return 0 ;
        // }
        return mini ;
    }
};