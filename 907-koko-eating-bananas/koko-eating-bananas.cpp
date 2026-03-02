class Solution {
public:
    double calcK(vector<int>& piles , int mid){
        
        double k = 0 ;
        
        for(int i : piles){
            k += ceil(double(i)/double(mid));
        }

        return k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int mini = INT_MAX ; 
        int maxi = INT_MIN ;

        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , piles[i]);
        }

        int s = 0 ;
        int e = maxi ;
        int mid ;
        int ans = maxi ;
        
        while(s<=e){
            mid = s + (e-s)/2;
            if(calcK(piles ,mid)<=h){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return ans;
    }
};