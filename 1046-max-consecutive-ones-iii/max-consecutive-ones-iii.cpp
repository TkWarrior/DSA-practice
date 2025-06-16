class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /* !Note - This question can also be framed as largest subarray with atmost k zeroes present */ 
   
   
        //Brute force approach
    //    int n = nums.size();
    //    int max_len = 0;
    //    int no_of_zeroes = 0;
    //    int len = 0;
    //    for(int i = 0 ; i<n ; i++){
    //         no_of_zeroes = 0;
    //         for(int j = i ; j<n ; j++){
    //             if(nums[j]==0){
    //                 no_of_zeroes++;
    //             }
    //             if(no_of_zeroes<=k){
    //                 len = j-i+1;
    //                 max_len = max(max_len,len);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //     }
    //     return max_len;

        // Optimal Soln -1

        // as soon as we encounter zeroe increase the the no_of_zeroes
        // if no_of_zeroes>k shift the left pointer until it reaches the zero element
        // if no_of_zeroes<=k then we have to find the length of the sliding window 
        // and decrease the zero by 1

    //     int n = nums.size();
    //     int l = 0 , r = 0 ; 
    //     int no_of_zeroes = 0;
    //     int len = 0;
    //     int max_len = 0 ;
    //     while(r<n){
    //         if(nums[r]==0){
    //             no_of_zeroes++;
    //         }
    //         // whenever the no_of_zero exceed the limit k we will shrink the window  in a sliding window at most k zeroes can be present
    //         while(no_of_zeroes>k){
    //             if(nums[l]==0){
    //                 no_of_zeroes --;
    //             }         
    //             l++;
    //         }
           
    //         if(no_of_zeroes<=k){
    //                 len = r-l+1;
    //                 max_len = max(max_len,len);
    //         }
    //         r++;
    //     }
    //    return max_len;

    // Most Optimal Soln 
    // In this case we've done slight change in the optimal soln instead of shrinking the sliding window at once once what we are doing is that we are not allowing to increase the length allowing only if there is no_of zeroes<= k 

    int l = 0, r = 0;
    int n = nums.size();
    int len = 0 , max_len = 0;
    int no_of_zeroes = 0;
    while(r<n){
        
        if(nums[r]==0) {
            no_of_zeroes++;
        }
        
        if(no_of_zeroes>k){
            if(nums[l]==0){
                no_of_zeroes--;
            }  
           l++;
        }

        if(no_of_zeroes<=k){
            len = r-l+1;
            max_len = max(max_len,len);
        }
        r++;
    }
    return max_len;
    }
};