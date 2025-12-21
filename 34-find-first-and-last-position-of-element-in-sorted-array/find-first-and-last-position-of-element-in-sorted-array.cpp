class Solution {
public:
    int bs(vector<int>&nums , int n , bool findFirstOcc ,int target){
        int s = 0 ;
        int e = n-1 ;
        int mid = s+ (e-s)/2;
        int idx = -1 ;
        while(s<=e){

            if(nums[mid]==target){
                idx = mid ; 
                if(findFirstOcc){
                    e = mid-1 ;
                }else{
                    s = mid+1 ;
                }       
            }else if(nums[mid]>target){
                e = mid-1 ;
            }else{
                s = mid+1 ;
            }
           mid = s+ (e-s)/2;
        }
        return idx ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>lis = {-1,-1};
        lis[0] = bs(nums , n ,true , target);
        lis[1] = bs(nums , n ,false , target);
        return lis;
    }
};