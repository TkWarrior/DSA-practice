class Solution {
public:
   
        void solve(int ind , vector<vector<int>>&ans ,vector<int>&candidates ,vector<int>&res, int target ){       
            if(target==0){
                ans.push_back(res);
             }               
   
            for(int i = ind ; i<candidates.size() ; i++){
           
                if(i>ind && candidates[i]==candidates[i-1]) {
                    continue;
                }
                if(candidates[i]>target){
                    break;
                } 
            
                res.push_back(candidates[i]);
                solve(i+1, ans , candidates ,res , target-candidates[i]);
                res.pop_back();
            }    
        }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>res; 
        
        solve(0 , ans ,candidates , res , target);     
        return ans;
    }
};