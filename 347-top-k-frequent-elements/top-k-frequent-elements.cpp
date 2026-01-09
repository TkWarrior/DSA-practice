class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>freq ; 
        vector<pair<int , int>>ans ;
        vector<int>res ;

        // storing the frequency inside the map
        for(int num : nums){
            freq[num]++;
        }
        
        // storing the pair of frequency and the associated element
        for(auto it : freq){
            
            cout<<it.first<<","<<it.second<<endl ;
            ans.push_back({it.second , it.first});
        }
        // printing it for debugging
        for(pair<int , int>&p :ans){
            cout<<p.first<<","<<p.second<<endl ;
        }
        // sorting in descending order
        sort(ans.rbegin() , ans.rend());
        // taking top k elements 
        for(int i = 0 ; i<k ; i++){
            res.push_back(ans[i].second);
        }
        return res ;
    }
};