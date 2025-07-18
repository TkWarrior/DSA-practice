class Solution {
public:
    vector<vector<int>>ans;
   
    void solve(vector<vector<int>>&ans ,vector<int>& candidates,vector<int>&res , int ind , int target){
        
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(res);
            }
            return;
        }
        
      // pick
         if(candidates[ind]<=target){
            res.push_back(candidates[ind]);
             solve(ans , candidates , res , ind , target-candidates[ind]);
            res.pop_back();
         }    

        //not pick
        solve(ans , candidates , res , ind + 1 , target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int ind = 0 ; 
        vector<int>res;

        solve(ans , candidates,res , ind , target );
        return ans;
    }
};