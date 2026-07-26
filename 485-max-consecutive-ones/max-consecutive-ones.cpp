class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0 ;
        int max_c = 0;
        int j = 0 ;
        int n = nums.size();

        while(j<n){
            if(nums[j]==1){
                c++;
                max_c = max(max_c ,c);
            }else{
                c = 0;
            }
            j++;
        }

        return max_c;
    }
};