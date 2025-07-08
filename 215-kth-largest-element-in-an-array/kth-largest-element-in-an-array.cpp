class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Approach 1-  Using Max Heap
        // priority_queue<int>pq;
        
        // int n = nums.size();
        
        // whenever we add element in the priority queue it got added in the maxHeap order like in the below case it will be formed as [6,5,4,1,2,3]
        // for(int i = 0 ; i<n ; i++){
        //     pq.push(nums[i]);
        // }
        
        // root element will get deleted now second largest element will take its place beacause internally it is implementing the maxHeap function by dafult
       
    //     for(int i = 1 ; i<k ;i++){
    //           pq.pop();
    //     }
    
    //    return pq.top();

        priority_queue<int , vector<int>, greater<int>>min_pq;

        // we'll create a minHeap of size k
        for(auto x:nums){
            min_pq.push(x);
            // as soon as the size of priority queue exceeds k pop the root element
            if(min_pq.size()>k){
                min_pq.pop();
            }
        }

        return min_pq.top();
    }
};