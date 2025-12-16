class Solution {
public:
 
    long long beautifulSubarrays(vector<int>& nums) {
       
        int n = nums.size();
        long long count = 0;
        unordered_map<int,int>mp ; 
        mp[0] = 1 ; 
        int prefix = 0;
  
        for(int i = 0 ; i<n ; i++){    
           prefix = prefix^nums[i];
           if(mp.count(prefix)){
                count+=mp[prefix];
           }
           mp[prefix]++;
        }

        return count;
    }
};