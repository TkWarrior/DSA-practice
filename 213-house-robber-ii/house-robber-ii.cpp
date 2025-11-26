class Solution {
public:
    int dp1[101];
    int dp2[101];
    int solve2(vector<int>&nums , int ind){
        if(ind<1) return 0 ; 
        if(dp2[ind]!=-1) return dp2[ind];
        if(ind==1){
            return dp2[ind] = nums[ind];
        }
        

        if(ind == 2){
            return dp2[ind] = max(nums[ind-1] , nums[ind]);
        }

        return dp2[ind] = max(nums[ind]+solve2(nums , ind-2) , solve2(nums ,ind-1));
    }
    
    int solve1(vector<int>&nums, int ind){
        if(ind<0) return 0 ; 
         if(dp1[ind]!=-1) return dp1[ind];
        if(ind==0){
            return dp1[ind] = nums[ind];
        }

        if(ind == 1){
            return dp1[ind] = max(nums[ind-1] , nums[ind]);
        }

        return dp1[ind] =max(nums[ind]+solve1(nums , ind-2) , solve1(nums ,ind-1));
    }

    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        int ind = n-1 ; 
        memset(dp1 , -1 , sizeof(dp1));
        memset(dp2 , -1 , sizeof(dp2));
        if(ind==0) return nums[ind];
        return max(solve1(nums , ind-1) , solve2(nums , ind)) ;
    }
};