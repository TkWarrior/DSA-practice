class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0 ;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int c = 0 ;

        for(int i = 0 ; i<n ; i++){
            s += nums[i];
            int rem = s%k;
            if(rem<0){
                rem += k ;
            }
            if(mp.find(rem)!=mp.end()){
                c +=  mp[rem];
                mp[rem]++;

            }else{
                mp[rem] = 1;
            }
                    
        }

        return c ;
    }

};