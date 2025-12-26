class Solution {
public:
    bool isPossible(vector<int>& nums,int mid, int maxOperations){
        long long count_operations =0;
        for(int num : nums){
            count_operations += ceil(num/double(mid))-1 ;
        }

        return count_operations<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1 ; 
        int e = *max_element(nums.begin(),nums.end());
        int ans = -1;
        // at each operation we have to minimize the maximum penalty
        
        while(s<=e){
            int mid = (s+e)/2;
            if(isPossible(nums , mid , maxOperations)){
                ans = mid ;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return ans ; 
    }
};