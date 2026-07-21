class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp = nums;
        sort(temp.begin() ,temp.end()) ;
        int x = 0 ;
        for(int i = 0 ; i < n-1 ; i++ ){
            if(nums[i+1]<nums[i]){
                x = i+1;
                break;
            }
        }

        for(int j = 0 ; j<n ; j++){
            if(temp[j] != nums[(j+x)%n]) return false;
        }

        return true;
    }
};