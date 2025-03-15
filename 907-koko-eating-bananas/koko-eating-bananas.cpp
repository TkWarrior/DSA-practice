class Solution {
public:
    int Max(vector<int>&piles){
        int ans = INT_MIN;
        for(int i = 0 ; i<piles.size() ; i++){
            ans = max(ans,piles[i]);
        }
        return ans;
    }
    long long calculateTime(vector<int>&piles,int mid){
        long long  totalTime = 0;
        for(int i = 0 ; i<piles.size() ; i++){
           totalTime += ceil((double)piles[i]/(double)mid);
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long  low = 1;
        long long  high = Max(piles);
        long long  mini = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            long long totalTime = calculateTime(piles,mid);
            if(totalTime<=h){
                mini = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return mini;
    }
};