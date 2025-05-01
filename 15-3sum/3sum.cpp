class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // brute force gives time limit exceed for large input time complexity O(N^3)
        // for(int i = 0 ; i<nums.size() ;i++){
        //     for(int j = i+1 ; j<nums.size() ;j++){
        //         for(int k = j+1 ;k<nums.size() ;k++){
        //             if(nums[i]+nums[j]+nums[k] == 0){
        //                 vector<int>temp = {nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //         } 
        //     }
        // }

        // Better Approach using hashing time complexity O(N^2*log(N))
        // set<vector<int>>st;
        // for(int i = 0 ; i<nums.size() ; i++){
        //     set<int>hashset;
        //     for(int j = i+1 ; j<nums.size() ; j++){
        //         int check = -(nums[i]+nums[j]);
        //         if(hashset.find(check)!=hashset.end()){
        //             vector<int>temp = {nums[i],nums[j],check};
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ans(st.begin(),st.end());
        // return ans;

        //Optimal Approach
        // using two pointer approach
       // In this two pointer approach first we have sorted the array
       // and then we have creted a 2d array to store the triplet 
       //then we have traverse the array at first we've checked if i>0 && nums[i] == nums[i-1] if that'e the case then we have to continue
       // first pointer will point to i+1;
       // second pointer to last element 
       // while(j<k) concition whenever the two pointer intersect it will terminate
       // store the sum of the three elements in the variable
       // if(sum<0) then we have to increase j++;
       // else if(sum>0) then we have to decrease k--
       // and if(sum == 0) we have to store tht triplet in temp array 
       // and then store that triple in the 2d array result
       //and then we have also applied two more contion of (while j<k && nums[j] == nums[j-1] j++) this condition is applied when sum is 0
       // and while(j<K && nums[k]==nums[k+1] k--) this condition is applied when sum is 0 
        // sort(nums.begin(),nums.end());
        // vector<vector<int>>res;
        // int j,k,sum;
        // int n = nums.size();
        // for(int i = 0 ; i<n ; i++){
        //     if(i>0 && nums[i]==nums[i-1]) continue;
        //     j = i+1;
        //     k = n-1;
        //     while(j<k){
        //         sum = nums[i]+nums[j]+nums[k];
        //         if(sum<0){
        //             j++;
        //         }
        //         else if(sum>0){
        //             k--;
        //         }
        //         else{
        //             vector<int>temp = {nums[i],nums[j],nums[k]};
        //             res.push_back(temp);
        //             j++;
        //             k--;
        //             while(j<k && nums[j]==nums[j-1]) j++;
        //             while(j<k && nums[k]==nums[k+1]) k--;
        //         }
        //     }
        // }
        // return res;

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                    
                }
            }
            
        }
        return ans;

    }
};