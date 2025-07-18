class Solution {
public:

    void solve(int ind , vector<vector<int>>&ans , vector<int>&nums , vector<int>&res){
        
        ans.push_back(res);
         
        for(int i = ind ; i<nums.size() ; i++){
            if(i>ind && nums[i]==nums[i-1]) continue;

            res.push_back(nums[i]);
            solve(i+1 , ans , nums ,res);
            res.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>>ans;
            vector<int>res;
            sort(nums.begin(),nums.end());
            solve(0,ans,nums,res);
            return ans;
    }
};