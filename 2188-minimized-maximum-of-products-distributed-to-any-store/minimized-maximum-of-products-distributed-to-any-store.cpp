class Solution {
public:

    bool possible(vector<int>& quantities , int mid , int size , int n){
        long long total = 0 ;
        for(int i = 0 ; i<size ; i++){ 
            total += (quantities[i]+mid-1)/mid ;
        
        }
        return total <= n ;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1 ;
        int  size = quantities.size() ; 
        int maxi = INT_MIN ; 
        
        for(int i = 0 ; i<size ; i++){
            maxi = max(maxi , quantities[i]);
        }

        int e = maxi ;
        int ans = -1 ; 

        while(s<=e){
            int mid = (s+e)/2 ; 
         
            if(possible(quantities , mid , size , n)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return ans; 
    }
};