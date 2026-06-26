class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0;
        int n = nums.size();
        int max_c = 0 ;

        for(int i = 0 ; i<n ; i++){
            if(nums[i]==1){
                c++;
                max_c = max(max_c , c);
                
            }else{
                c = 0;
            }
        }

        return max_c;
    }
};