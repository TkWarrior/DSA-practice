class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        unordered_map<int,int>umap;

        for(int i : nums){
            umap[i]++;
        }

        for(auto it:umap){
            if(it.second>1){
                return it.first;
            }
        }

        return -1;
    }
};