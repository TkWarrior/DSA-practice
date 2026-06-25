class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>arr = nums;

        sort(arr.begin(),arr.end());

        int k = 0 ;
        int n = nums.size();

        for(int i = 0 ; i<n-1 ; i++){
            if(nums[i+1]<nums[i]){
                k = i+1;
                break;
            }
        }

        for(int j = 0 ; j<n ; j++){
            if(nums[(j+k)%n] != arr[j]){
                return false;
            }
        }

        return true;
    }
};