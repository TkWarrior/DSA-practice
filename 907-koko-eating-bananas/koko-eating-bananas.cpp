class Solution {
public:
    // Binary search on answer
    double calculateHour(vector<int>& piles , int mid){
       
        double sum = 0 ; 
        int n = piles.size() ; 
       
        for(int i = 0 ; i<n ; i++){
            // If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour. - through this statement of the question we can interpret that we've take the ceil value
            sum += ceil(double(piles[i])/double(mid));
        }

        return sum ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
     
        int maxi = INT_MIN ; 
        int n = piles.size() ; 
        
        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , piles[i]);
        }

        int s = 0 ;
        int e = maxi ; 
        int ans = INT_MAX;
        while(s<=e){
            int mid = (s+e)/2;
            // before the guard returns
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