class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int diff = 0 ;
        int n = nums.size();
        if(n==1 && (nums[0]==0 || nums[0]==1)){
            if(nums[0]==0) return 1;
            if(nums[0]==1) return 0;
        }
        for(int i = 0 ; i<n-1 ; i++){
            diff = nums[i+1] - nums[i];
            if(diff>1){
                return  nums[i]+diff-1;
            }
        }
        if(nums[0]>0) return 0;
        return n;
    }
};