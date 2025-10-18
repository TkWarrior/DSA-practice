class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>umap ; 
        int n = nums.size();

        for(int i = 0 ; i<n ; i++){
            umap[nums[i]]++;
        }

        sort( nums.begin() , nums.end() , [&](int a , int b) {
             if(umap[a]==umap[b]){
                return a>b ; 
             }
             return umap[a]<umap[b];
        });
          
        return nums;

    }
};