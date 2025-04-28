class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool>hash(n+1,false);
        vector<int>ans;
        for(int num:nums){
            hash[num] = true;
        }
        for(int i = 1 ; i<=n ; i++){
            if(!hash[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};