class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>umap ; 
        int n = numbers.size();

        for(int i = 0 ; i<n ; i++){
            int key = target - numbers[i];
            if(umap.find(key)!=umap.end()){
                return {umap[key]+1 , i+1};
            }
            umap[numbers[i]]= i;
        }

        return {};
    }
};