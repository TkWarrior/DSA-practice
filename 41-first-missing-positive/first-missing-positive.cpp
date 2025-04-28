class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool>hash(n+1,false);
        // for each loop
        for(int num:nums){
            if(num>0 && num<=n) hash[num] = true;
        }

        // now we will use another for loop to find smallest +ve integer in 
        for(int i=1 ; i<=n ; i++){
            if(!hash[i]){
                return i;
            }
        }
        // if hash array contain all true values from 1 to n then 

        return n+1;
    }
};