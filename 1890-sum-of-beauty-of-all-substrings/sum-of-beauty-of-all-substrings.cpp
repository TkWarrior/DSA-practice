class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        
        int c = 0 ;
        string res = "";

        for(int i = 0 ; i<n ; i++){
            int mp[26] = {0};
            int maxi = 0;
            for(int j = i ; j<n ; j++){
                
                mp[s[j]-'a']++;
                maxi = max(maxi ,mp[s[j]-'a']);
                int mini = INT_MAX ;
                for(int k = 0 ; k<26 ; k++){
                   if(mp[k]>0){
                        
                        mini = min(mini ,mp[k]);
                   }                  
                }
                
                c += (maxi-mini) ;         
            }
        }  
        return c ;
     
    }
};