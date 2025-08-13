class Solution {
public:
    int missingNumber(vector<int>& nums) {

        vector<bool>hash(10000,false);
        int n = nums.size();
        int j ; 
        for(int i = 0 ; i<n ; i++){
            hash[nums[i]] = true;
        }

        for( j = 0 ; j<n ; j++){
            if(hash[j]==false){
                break;
            }
        }
        return j;
    }
};