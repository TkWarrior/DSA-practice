class Solution {
public:
    
    double calculateThreshold(vector<int>& nums , int mid){
        int n = nums.size() ; 
        double sum = 0 ; 
        for(int i = 0 ; i<n ; i++){
            sum += ceil(double(nums[i])/double(mid));
        }

        return sum ;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size() ; 
        int maxi = INT_MIN ;
        
        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , nums[i]);
        }

        int s = 1 ; 
        int e = maxi ; 
        int ans = INT_MAX ;
      
        while(s<=e){
            int mid = (s+e)/2;
            // as given in the question
            if(calculateThreshold(nums , mid) <= threshold){
                ans = mid ; //  store the value in the answer
                e = mid - 1 ;
            }else{
                s = mid + 1 ;
            }
        }

        return ans ; 
        
    }
};