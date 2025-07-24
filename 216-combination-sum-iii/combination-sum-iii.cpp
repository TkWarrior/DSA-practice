class Solution {
public:
    void solve(int ind ,vector<int>&res ,vector<vector<int>>&ans ,int n ,int k) {
        if(n==0 && k==0){
            ans.push_back(res);
        }
        for(int i = ind ; i<10 ; i++){
            if(i>ind && i == i-1) continue;
            if(i > n) break;
            res.push_back(i);
            solve(i+1,res , ans ,n-i , k-1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // if n is odd start with 1 other wise start with 2
        // if k>n will give empty array
        vector<int>res;
        vector<vector<int>>ans;
        int ind = 1;
        solve(ind , res , ans , n , k);
        return ans;
    }
};