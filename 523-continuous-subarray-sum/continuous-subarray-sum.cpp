class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int s = 0 ;
        mp[0] = -1 ;

        for(int i = 0 ; i<n ;i++){
            s += nums[i];
            int rem = s%k ;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2){
                    return true;
                }  
            }
            mp.insert({s%k , i});
        }

        return false;

    }
};