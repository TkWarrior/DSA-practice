class Solution {
public:
    //Classic Question of a hashmap
    bool isPrime(int n ){
        if(n<2){
            return false;
        }
        for(int j = 2 ; j<=sqrt(n) ; j++){
            if(n%j == 0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>umap;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            umap[nums[i]]++;
        }

      
       for(int i = 0 ; i<n ; i++){
           if(isPrime(umap[nums[i]])){
               return true;
           }
       }
        return false;;
    }
};