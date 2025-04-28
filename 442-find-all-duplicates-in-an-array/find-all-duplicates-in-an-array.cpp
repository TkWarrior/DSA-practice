class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>umap;
        int n = nums.size();
        for(int num:nums){
            umap[num]++;
        }
        for(auto it:umap){
            if(it.second>1) ans.push_back(it.first);
        }

        return ans;
    }
};