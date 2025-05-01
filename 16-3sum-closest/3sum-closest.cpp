class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int closest = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            // if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
             
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];   
                
                if(sum<target) j++;
                else if(sum>target) k--;
                else return sum;
                int diff = abs(sum-target);
                if(diff<mini){
                    mini = diff;
                    closest = sum;
                }
            }
        }
        return closest;
    }
};