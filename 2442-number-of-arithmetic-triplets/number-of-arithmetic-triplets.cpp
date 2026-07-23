class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int , int>mp;
        int n  = nums.size();
        int c = 0;

        for(int i = 0 ; i<n ; i++){
            mp[nums[i]] = i;
        }

        for(int i = 0 ; i<n ; i++){
            if(mp.find(nums[i]+diff)!=mp.end() && mp.find(nums[i]+2*diff)!=mp.end()){
                c++;
            }
        }

        return c ;
    }
};