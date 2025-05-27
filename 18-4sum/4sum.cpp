class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // brute force -  using four loops
        //better  - using set and hashset one loop gets reduce
        set<vector<int>>st;
        int n = nums.size();
        for(int i= 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                set<long long>hashset;
                for(int k = j+1 ; k<n ; k++){ 
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
                
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
        // optimal - using two  pointer fixing two pointer i and j fixed nd moving k and l moving
    }
};