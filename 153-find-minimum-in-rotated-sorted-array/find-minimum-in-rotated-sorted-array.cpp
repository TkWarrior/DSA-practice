class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int s = 0 ;
        int e = n-1 ; 
      
        if(nums[s]<=nums[e]){
            return nums[s] ;
        }

        if(n == 1){
            return nums[0] ;
        }
        int mini = INT_MAX ; 
       
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[s]<=nums[mid]){
                mini = min(mini , nums[s]);
                s = mid+1 ; // in rotated sorted array the minimum will always be right side        
            }else{
                mini = min(mini , nums[mid]);
                e = mid-1 ; 
            }
        }

        return mini ;

    }
};