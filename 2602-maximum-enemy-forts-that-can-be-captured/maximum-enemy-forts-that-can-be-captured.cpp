class Solution {
public:
    int captureForts(vector<int>& forts) {
        int l = 0 , r = 0;
        int n = forts.size() ;
        int maxi = 0;

        while(r<n){
            if(forts[r]){
                if(forts[l] == -forts[r]){
                    maxi = max(maxi , r-l-1);
                }
                l = r; 
            }
           
            r++ ; 
        }

        return maxi ; 
    }
};