class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // better soln 
        set<vector<int>>st;
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                set<long long>hashset;
                for(int k = j+1 ; k<nums.size() ; k++){
                    // to prevent integer overflow we split the sum 
                    long long sum = nums[i] + nums[j] ;
                    sum+=nums[k];
                    long long fourth = target - sum;
                    // check if the fourth element present in the hashset
                    // if it's present than store the quadraplet in the temp vector
                    // sort it and then inset the temp vector to the set data structure
                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k],int(fourth)};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    } 
                    // enter nums[k] elment to the hashset at every iteration
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;

        // Optimal Soln
        // vector<vector<int>>ans;
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // for(int i = 0 ; i<n ; i++){
        //     if(i>0 && nums[i]==nums[i-1]) continue;

        //     for(int j = i+1 ; j<n ; j++){
        //         if( j>i+1 && nums[j]==nums[j-1]) continue;
                
        //         int k = j+1;
        //         int l = n-1;
        //         while(k<l){
        //             long long sum  = nums[i] + nums[j];
        //             sum+=nums[k];
        //             sum+=nums[l];
        //             if(sum<target) k++;
        //             else if(sum>target) l--;
        //             else {
        //                 vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
        //                 ans.push_back(temp);
        //                 k++;
        //                 l--;
        //                while(k<l && nums[k] == nums[k-1] ) k++;
        //                while(k<l && nums[l] == nums[l+1] ) l--;
        //             }
        //         }
        //     }
        // }
        
        // return ans;
    }
};