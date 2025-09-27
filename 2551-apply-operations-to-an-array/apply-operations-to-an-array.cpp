class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int l = 0 ; 
        int r = 0 ; 
        int n = nums.size();

        for(int i = 0 ; i<n ; i++){
            if(i+1 == n) break;
            if(nums[i]==nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
            else{
                continue;
            }
        }

        while(r<n){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }

        return nums;
    }
};