class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 ;
        int j = 0 ;
        int max_ws =0 ;
        int ws = 0 ;

        while(j<n){
            if(nums[j]==0){
                k--;
            }
            while(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            ws = j-i+1;
            max_ws = max(ws , max_ws);
            j++;
        }

        return max_ws;
    }
};