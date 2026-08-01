class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int s = 0 ;
        mp[0] = 1 ;
        int c = 0 ;

        for(int i = 0 ; i<n ; i++){
            s += nums[i];
            if(mp.find(s-k)!=mp.end()){
                c += mp[s-k];
            }
            mp[s]++;
        }

        return c ;
    }
};