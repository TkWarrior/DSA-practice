class Solution {
public:

    double calculateHour(vector<int>& piles , int mid){
       
        double sum = 0 ; 
        int n = piles.size() ; 
       
        for(int i = 0 ; i<n ; i++){
            sum += ceil(double(piles[i])/double(mid));
        }

        return sum ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
     
        int maxi = INT_MAX ; 
        int n = piles.size() ; 
        
        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , piles[i]);
        }

        int s = 0 ;
        int e = maxi ; 
        int ans = INT_MAX;
        while(s<=e){
            int mid = (s+e)/2;
            if(calculateHour(piles , mid)<=h){
                ans = mid ;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return ans ; 
    }
};