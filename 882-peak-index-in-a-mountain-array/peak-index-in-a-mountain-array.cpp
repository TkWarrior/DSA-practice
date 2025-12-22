class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size() ; 
        int s = 0 ; 
        int e = n-1;
        int mid;
        
        while(s<=e){
            mid = (s+e)/2;
            if(arr[s]==arr[mid]){
                s++;
            }
            if(arr[mid] == arr[e]){
                e--;
            }
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                break ;
            }
            if(arr[mid+1]>arr[mid]){
                s = mid+1;
            }else{
                e = mid;
            }
        }

        return mid;
    }
};