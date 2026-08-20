class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0 ;
        int j = 0 ;
        int n = nums.size();
        int mask = 0 ;
        int maxi = 1 ; 

        while(j<n){

            while((mask & nums[j]) != 0){
                mask = mask ^ nums[i];
                i++;
            }     
            maxi = max(maxi , j-i+1);      
            cout<<j-i+1<<endl ;          
            mask = mask | nums[j];
            j++;
        }   

        // return maxi ;

        // int maxi = 1 ; 
        // int mask = 0 ;
        // int n = nums.size();

        // for(int i = 0 ; i<n ; i++){
        //     mask = 0 ;
        //     for(int j = i ; j<n ; j++){
        //         if((mask&nums[j])!=0){
        //             break;
        //         }
        //         maxi = max(maxi , j-i+1);
        //         mask |= nums[j];
        //     }
        // }

        return maxi ;
    }
};