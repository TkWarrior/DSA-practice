class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       //solution using hash map

       //in this approach we've used hash map store the element with it's corresponding indices
       //after that we have checked the key (target - nums[i]) present in the map and if it is present then we will return the corressponding value associated with it and the iteratator which is being currently pointed in the array
       unordered_map<int,int>umap;
        for(int i = 0 ; i<nums.size() ; i++){
            int key = target - nums[i];
            //if key is present 
            if(umap.find(key)!=umap.end()){
                return {umap[key] , i};
            }
            umap[nums[i]] = i;
        }
        return {-1,-1};
    }
};