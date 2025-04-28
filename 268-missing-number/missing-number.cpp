class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using hashing
        int n = nums.size();
        vector<bool>hash(10000,false);
        int i, j;
        for(i = 0 ; i<nums.size() ; i++){
            hash[nums[i]] = true;
        }
        for(j = 0 ; j<nums.size() ; j++){
            if(!hash[j]){
                break;
            }
        }
        return j;
    }
};