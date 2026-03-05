class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1){
            return 1;
        }

        int i = 1 ;
        int j = 1 ;
       
        while(i<n ){
            if(nums[j-1]!=nums[i]){
                nums[j] = nums[i];
                j++;
            }else{
                i++;
            }
        }

        return j ;
    }
};