class Solution {
public:

    //using heap sort time complexity - O(nlogn)
   void heapify(vector<int>&arr,int n ,int i){
        int left = 2*i+1;
        int right = 2*i+2;
        // since we're creating the max heap
        int largest = i;
        
        if(left<n && arr[left]>arr[largest]){
            largest = left;
        }
        
        if(right<n && arr[right]>arr[largest]){
            largest = right;
        }
        
        if(largest!=i){
            
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    
    void buildHeap(vector<int>&arr,int n){
            
        for(int i = n-2/2 ; i>=0 ; i--){
            heapify(arr,n,i);
        }
        
    }
    
    vector<int>sortArray(vector<int>& nums) {
        // code here
        int n = nums.size();
        buildHeap(nums,n);
        
        for(int i = n-1 ; i>=0 ; i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
       
        return nums;
    }
};