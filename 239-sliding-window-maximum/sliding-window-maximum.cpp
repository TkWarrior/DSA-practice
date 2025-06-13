class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Brute force approach Time Complexity - O(N*K)
        // int n = nums.size();
        // vector<int>sw;
        // for(int i = 0 ; i<=n-k ; i++){
        //     int maxi = INT_MIN;
        //     for(int j = i ; j < k+i ; j++){
        //         if(nums[j]>maxi){
        //             maxi = max(maxi,nums[j]);
        //         }
               
        //     }
        //     sw.push_back(maxi);
        // }
        // return sw;


        // Optimal Approach - Using deque 

        deque<int>dq;
        int n = nums.size();
        vector<int>result;
        for(int i = 0 ; i<n ; i++){
            //storing only window element in the deque 
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if( i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};