class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //Brute force
       
    //    int n = s.length();
    //     int maxi = 0 ;
      
    //    for(int i = 0 ; i<n ; i++){
    //        int hash[256] = {0};
    //        for(int j=i ; j<n ;j++){
    //             if(hash[s[j]]==1){
    //                 break;
    //             }
    //             int len = j-i+1;
    //             hash[s[j]] = 1;
    //             maxi = max(len,maxi);
    //        }
       
    //    }
    //    return maxi;

        // Optimal soln - using two pointer & sliding window + hashmap
        unordered_map<char,int>hashmap;
        int n = s.length();
        int l = 0 , r= 0;
        int maxi = 0;
        int len = 1;
        while(r<n){
            if(hashmap.find(s[r])!=hashmap.end()){
                if(hashmap[s[r]]>=l){
                     l = hashmap[s[r]]+1;
                }         
            }
            len = r-l+1;  
            hashmap[s[r]] = r;  
            maxi = max(maxi , len);
            r++;
        }
        if(l==0){
            return n;
        }
        return maxi;
    }
};