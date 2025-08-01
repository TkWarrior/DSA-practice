class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
       int n = tasks.size();
       vector<int>result ; 
       vector<array<int,3>>sortedTasks;
       // we  are making the array of enqueue time , processing time and index
       for(int i = 0 ; i<n ; i++){
            int enqueueTime = tasks[i][0];
            int processingTime = tasks[i][1];

            sortedTasks.push_back({enqueueTime,processingTime,i});
       }

       sort(sortedTasks.begin(),sortedTasks.end());
       long long curr_time = 0;
       
        // we've to create the min heap
        // we've created the priority queue of pair of the processing time, index
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        int ind = 0 ; 

        while(ind<n || !pq.empty()){
            if(pq.empty() && curr_time<sortedTasks[ind][0]){
                curr_time = sortedTasks[ind][0];
            }

            while(ind<n && sortedTasks[ind][0]<=curr_time){
                pq.push({sortedTasks[ind][1],sortedTasks[ind][2]});
                ind++;
            }

            pair<int , int>curr_task ; 
            curr_task = pq.top();
            pq.pop();
            curr_time += curr_task.first;
            result.push_back(curr_task.second);

        }

        return result;
        
    }
};