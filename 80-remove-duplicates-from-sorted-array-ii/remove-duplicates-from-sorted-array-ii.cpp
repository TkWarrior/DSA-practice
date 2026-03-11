class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n<=2){
            return n;
        }

        int i = 2 ;
        int j = 2 ;

        while(i<n && j<n){
            if(nums[j-2]!=nums[i]){
                nums[j] = nums[i];
                j++;
            }
            i++;
        }

        return j ;
    }
};