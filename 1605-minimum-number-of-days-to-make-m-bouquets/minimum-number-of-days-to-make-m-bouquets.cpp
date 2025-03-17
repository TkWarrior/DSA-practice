class Solution {
public:
// Brute Force Apprroach
    int minimum(vector<int>&weights){
        int mini = INT_MAX;
        for(int i = 0 ; i<weights.size() ; i++){
            mini = min(mini,weights[i]);
        }
        return mini;
    }
    int maximum(vector<int>&weights){
        int maxi = INT_MIN;
        for(int i = 0 ; i<weights.size() ; i++){
            maxi = max(maxi,weights[i]);
        }
        return maxi;
    }
    bool possible(vector<int>& bloomDay,int mid , int m ,int k){
        int count = 0;
        int noOfBouque = 0;
        for(int j = 0 ; j<bloomDay.size() ; j++){
            if(bloomDay[j]<=mid){
                count++;
            }
            else{
                noOfBouque+=count/k;
                count = 0;
            }
        }
        noOfBouque+=count/k;
        if(noOfBouque>=m){
            return true;
        }
        return false;
       
    }
    int minDays(vector<int>& bloomDay, long long m, long long k) {
        
        int n = bloomDay.size();
        int low = minimum(bloomDay);
        int high = maximum(bloomDay);
        long long prod = m*k;
        if(n<prod){
            return -1;
        }
        //this approach will give TLE so we will now solve it using binary Search
        // for(int i = minimum(bloomDay) ; i<=maximum(bloomDay) ; i++){
        //     if(possible(bloomDay,i,m,k)){
        //         return i;
        //     }
        // }
        
        //Optimized Approach
        //finally able to optimize it by my self although for brute and to know the intution i have to gont through the video solution 
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};