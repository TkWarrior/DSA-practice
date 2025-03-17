class Solution {
public:
    int maxWeight(vector<int>&weights){
        int maxi = INT_MIN;
        for(int i = 0 ; i<weights.size() ; i++){
            maxi = max(maxi,weights[i]);
        }
        return maxi;
    }

    int requiredDays(vector<int>&weights , int capacity){
        int days = 1;
        int load = 0;
        for(int i =0 ; i<weights.size() ; i++){
            if(load+weights[i]>capacity){
                days++;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxWeight(weights);
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid = (low+high)/2;
            int totalDays = requiredDays(weights,mid);
            if(totalDays<=days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        } 
        return low;   
    }
};