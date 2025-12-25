class Solution {
public:

    bool possible(vector<int>&weights , int mid , int days , int n ){
        int load = 0;
        int no_of_days = 1 ;

        for(int i = 0 ; i<n ; i++){
            if(load+weights[i]>mid){
                load = weights[i];
                no_of_days++;
            }else{
                load += weights[i] ;
            }
      
        }

        return no_of_days<=days ;
    }

    int shipWithinDays(vector<int>& weights, int days ) {
       
       int n = weights.size() ; 

        int sum = accumulate(weights.begin() , weights.end() , 0);
        cout<<sum ; 
        int maxi = INT_MIN ; 

        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , weights[i]);
        }

        int s = maxi; 
        int e = sum ; 
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2 ;
            cout<<mid<<endl; 
            if(possible(weights , mid  , days , n)){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        
        return s ; 
    }
};