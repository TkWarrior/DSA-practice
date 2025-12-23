class Solution {
public:
   
    double calcK(vector<int>&piles ,int mid , int n, int h){
        double k = 0;
        
        for(int i : piles){
            k += ceil(double(i)/double(mid));
        }

        return k ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
     
       int n = piles.size();

        int mini = INT_MAX ; 
        int maxi = INT_MIN ;


        for(int n : piles){
            maxi = max(maxi , n);
        }

        int s = 0 ;
        int e = maxi ;
        int ans = INT_MAX;
        
        while(s<=e){
            int mid = (s+e)/2 ; 
            if(calcK(piles , mid ,n , h)<=h){
                ans = mid ; 
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
    
        return ans ; 
    }
};