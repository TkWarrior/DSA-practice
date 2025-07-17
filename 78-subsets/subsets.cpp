class Solution {       
public:
    // have to remember this pattern many question of subsequence can be solved by this
    void solve(int index , vector<int>&nums , vector<vector<int>>&ans,vector<int>&result ,int n){
        if(index==n){
            ans.push_back(result);
            
            return ; 
        }
        // pick the index element and it to the result array
        result.push_back(nums[index]);
        
        solve(index+1 , nums , ans , result , n);
        // remove from the result array don't pick the element
        result.pop_back();
        solve(index+1 , nums , ans ,result , n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans ; 
         int index = 0 ; 
         int n = nums.size();
         vector<int>result;
         solve(index , nums ,ans , result , n);

         return ans;
    }
};