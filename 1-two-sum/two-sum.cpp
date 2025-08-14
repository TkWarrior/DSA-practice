class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
        unordered_map<int,int>umap;
       int key = 0 ;

       for(int i = 0 ; i<n ; i++){
           
            key = target - nums[i];

            if(umap.find(key)!=umap.end()){
                return {umap[key] , i};
            }

            umap[nums[i]] = i;
       }

       return {};
      
    }
};