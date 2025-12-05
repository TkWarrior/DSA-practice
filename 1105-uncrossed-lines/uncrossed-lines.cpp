class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2 , int m , int n){
       
        if(m==0 || n ==0){
            return 0 ;
        }

        if(dp[m][n] != -1) return dp[m][n];

        if(nums1[m-1] == nums2[n-1]){
            return dp[m][n] = 1+solve(nums1 , nums2 , m-1 , n-1);
        }

        return dp[m][n] = max(solve(nums1 , nums2 , m-1 , n) , solve(nums1 , nums2 , m ,n-1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // similar to edit distance problem
        int m = nums1.size() ; 
        int n = nums2.size() ; 
        memset(dp , -1 , sizeof(dp));
        return solve(nums1 , nums2 , m , n); 
    }
};