class Solution {
public:
    int countBouquet(vector<int>&bloomDay , int mid , int k){
        int n = bloomDay.size();
        int count = 0 ;
        int no_of_bouque = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(bloomDay[i]<=mid){
                count++;
            }else{
                no_of_bouque += count/k ;
                count = 0 ;
            }
        }

        no_of_bouque += count/k;
        return no_of_bouque;
    }
    int minDays(vector<int>& bloomDay, long long  m, long long k) {
        int n = bloomDay.size() ; 

        if(n < m*k) return -1 ;

        int maxi  = INT_MIN ; 
        int mini = INT_MAX ;

        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , bloomDay[i]);
        }

        for(int i = 0 ; i<n ; i++){
            mini = min(mini , bloomDay[i]);
        }

        int s = mini ;
        int e = maxi ;
        

        while(s<=e){
            int mid = (s+e)/2;

            if(countBouquet(bloomDay,mid ,k)>=m){
              
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return s ;

    }
};