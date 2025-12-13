class Solution {
public:
   
    int maximumUniqueSubarray(vector<int>& nums) {
        // find the subarray with maximum sum that has unique elements
        unordered_map<int , int>umap ; 
        int n = nums.size();
        int  l = 0 ; 
        int r = 0 ;
        int maxi = 0 ; 
        int sum = 0;
        
        while(r<n){
            if(umap.find(nums[r])!=umap.end()){
                sum = 0 ;
                if(umap[nums[r]]>=l){
                    l = umap[nums[r]]+1;
                }  
                for(int i = l ; i<r ; i++){
                    sum += nums[i];
                }        
            }
            umap[nums[r]] = r ;
            sum += nums[r] ;
            maxi = max(maxi , sum);
            r++;
        }
        cout<< "left end :"<< l;
        cout<< "right end :"<< r;

        // for(int i= l ; i<r ; i++){
        //     sum += nums[i];
        // }
        return maxi;

    }
};