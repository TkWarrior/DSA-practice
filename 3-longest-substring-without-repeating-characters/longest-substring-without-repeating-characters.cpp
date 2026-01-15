class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0 ; 
        int r = 0 ; 
        int max_length = 0 ;

        for(int i = 0 ; i<n ; i++){
            unordered_map<int,int>mp ; 
            for(int j = i ; j<n ; j++){
                if(mp[s[j]]==1){
                    break ;
                }
                int ws = j-i+1;
                mp[s[j]] = 1 ;
                max_length = max(max_length , ws);
            }
        }

        return max_length ;
    }
};