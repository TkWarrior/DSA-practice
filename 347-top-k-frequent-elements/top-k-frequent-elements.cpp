class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // first we will make store elements with its corressponding frequencies in unoredered map
        // at this point the element is mapped as {element,frequency} 
       int n = nums.size();

       vector<int>ans;

       unordered_map<int ,int> umap ; 

       for(auto x:nums){
            
            umap[x]++;
       }
       

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // we're storing element in priority queue from minimumm to maximum 
       for(auto x:umap){
            pq.push(make_pair(x.second,x.first));

            if(pq.size()>k){
                pq.pop();
            }
       }

       while(!pq.empty()){
            pair<int,int>temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
       }
  
        return ans;
    }
};