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

        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int j,k,sum;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            j = i+1;
            k = n-1;
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};