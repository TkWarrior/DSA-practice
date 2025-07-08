class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // we will create a priority queue which will store the element and the absolute difference of array element and x
        // we'll create the max_heap
        priority_queue<pair<int,int>>pq;
        for(auto i:arr){
            int diff = abs(i-x);
            pq.push(make_pair(diff,i));
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};