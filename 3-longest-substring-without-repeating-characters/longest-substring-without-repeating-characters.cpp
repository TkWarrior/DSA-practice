class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //Brute force
       unordered_map<char,int>umap;
       int n = s.length();
        int maxi = 0 ;
      
       for(int i = 0 ; i<n ; i++){
         
            umap = {};
           for(int j=i ; j<n ;j++){
                if(umap.find(s[j])!=umap.end()){
                    break;
                }
                int len = j-i+1;
                umap[s[j]] = 1;
                maxi = max(len,maxi);
           }
       
       }
       return maxi;
    }
};