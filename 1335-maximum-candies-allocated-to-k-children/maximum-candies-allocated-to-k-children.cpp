class Solution {
public:
    bool isPossible(vector<int>& candies , int mid ,  long long k){
        long long total = 0 ;
        for(int c : candies){        
            total += c/mid;     
        }
        return total >= k ;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
       
        int s = 1 ;
        int e = *max_element(candies.begin(),candies.end()) ; 
        long long ans = 0 ; 

        while(s<=e){
            int  mid = s+(e-s)/2;
            if(isPossible(candies , mid , k)){
                ans = mid ; 
                s = mid+1;
            }else{
                e = mid-1;
            }
        }

        return ans ;
    }
};