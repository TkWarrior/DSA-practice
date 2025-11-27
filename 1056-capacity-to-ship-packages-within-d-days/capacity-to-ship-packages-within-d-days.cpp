class Solution {
public:
   
    bool isPossible(vector<int>& weights , int capacity , int days){
            int load = 0; // iitially there is no load in the ship
            int no_of_days = 1 ; // start from the day 1

            for(int i=0 ; i<weights.size() ; i++){
                // if ship exceeds the capacity
                if(load + weights[i] > capacity){
                    load = weights[i] ;// initialize the new weight from the next day
                    no_of_days++ ; // start from the next day
                }else{
                    load += weights[i] ; // add weights within that day itself
                } 
            }

            return no_of_days <= days ;
      
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
       
        int maxi = INT_MIN ; 
        int n = weights.size() ;

        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , weights[i]);
        }

        int low = maxi ; 
        int high = accumulate(weights.begin() , weights.end() ,0) ;
        int ans = 0 ; 

        while(low<=high){
            int mid = (low+high)/2 ;
            // if it is possible to ship the packageof of capacity mid 
            if(isPossible(weights , mid , days)){
                ans =  mid ; 
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        cout<<ans ;
        
       return ans;
    }
};