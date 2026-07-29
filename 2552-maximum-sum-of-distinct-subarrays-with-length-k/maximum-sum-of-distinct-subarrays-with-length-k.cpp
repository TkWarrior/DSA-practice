class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0 ;
        int j = 0 ;
        int n = nums.size();
        long long s = 0 ;
        long long max_s = 0 ;
        unordered_set<int>st ;

        while(j<n){ 
            
            while(st.find(nums[j])!=st.end()){
                s -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            s += nums[j];
            st.insert(nums[j]);
            if(j-i+1 == k){
                max_s = max(max_s , s);
                cout<<max_s<<endl;
                s -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
            
        }

        return max_s;
    }
};