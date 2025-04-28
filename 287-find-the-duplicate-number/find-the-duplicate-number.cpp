class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int j = 1 ;
        int i = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        while(i<n && j<n){
            int result = nums[j]^nums[i];
            if(result == 0){
                return nums[i];
            }
            else{
                i++;
                j++;
            }
        }
        return -1;
    }
};