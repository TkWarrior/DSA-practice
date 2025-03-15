class Solution {
public:
    int findMax(vector<int>&nums){
        int maxi = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }

    int calculateThreshold(vector<int>& nums,int mid){
       int totalThreshold = 0;
       for(int i = 0 ; i<nums.size() ; i++){
            totalThreshold += ceil((double)nums[i]/(double)mid);
       }
       return totalThreshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        //similar to koko eating banana problem
        int low = 1;
        int high = findMax(nums);
        int ans  = INT_MAX;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            int totalThreshold = calculateThreshold(nums,mid);
            if(totalThreshold<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};