class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        int j = 1;
        int res ;
        sort(nums.begin() , nums.end());

        while(i<n && j<n){
            res = nums[j]^nums[i];
            if(res==0){
                return nums[i];
            }
            i++;
            j++;
        }

        return -1 ;
    }
};