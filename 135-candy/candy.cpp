class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int count = 0 ; 
        vector<int>c(n);
        c[0] = 1 ; 
        
        for(int i = 0 ; i<n ; i++){
            c[i] = 1 ; 
        }

        // left -> right traversal 
        for(int i = 1 ; i<n ; i++){
            if(ratings[i-1] < ratings[i]){
                c[i] = c[i-1]+1 ; 
            }
        }

        for(int i = n-2 ; i>=0 ; i--){
            if(ratings[i+1] < ratings[i]){
                c[i] = max(c[i] , c[i+1]+1);
            }
        }

        for(int i = 0 ; i<n ; i++){
            count += c[i];
        }

        return count ;
    }
};