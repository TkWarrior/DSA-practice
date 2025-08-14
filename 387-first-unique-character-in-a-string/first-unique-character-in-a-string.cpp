class Solution {
public:
    int firstUniqChar(string s) {
     
       unordered_map<char,int>umap ; 
       int n = s.length();
       
       for(int i = 0 ; i<n ; i++ ){
            umap[s[i]]++;
       }

       for(int j = 0 ; j < n ;j++){
            if(umap[s[j]]==1){
                return j;
            }
       }

       return -1;
    }
};