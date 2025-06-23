class Solution {
public:
    int lessThanOrEqualTo(vector<int>&nums,int goal){
        int count = 0;
        int sum = 0;
        int l = 0 , r = 0 ;
        int n = nums.size();
        // work for the test cases like nums = [0,0,0,0,0] and goal = 0
        if(goal<0){
            return 0;
        }
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum = sum - nums[l];
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // generate all binary subarray with sum == goal
        //  brute force
        //  int count = 0 ;
        //  int sum = 0 ;
        //  for(int i = 0 ; i<nums.size() ; i++){
        //      sum = 0;
        //      for(int j = i; j<nums.size() ; j++){
        //          sum +=  nums[j];
        //          if(sum == goal){
        //              count++;
        //          }
        //          if(sum>goal){
        //              break;
        //          }
        //      }
        //  }
        //  return count;

        // Optimal soln - 2 pointer + sliding window

        // math behind this problem is
        // no of subarray with sum equal to k = no of subarray<=goal - no of
        // subarray<=goal-1
        

        return lessThanOrEqualTo(nums,goal) - lessThanOrEqualTo(nums,goal-1);
    }
};