class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int required_count = n ;

        if(m<n){
            return "";
        }
        unordered_map<char , int>mp ; 

        for(char&ch : t){
            mp[ch]++;
        }

        int l = 0 ;
        int r = 0 ;
        int min_ws = INT_MAX ;
        int ws = 0 ;
        int start_l = 0 ;

        while(r<m){
            if(mp[s[r]]>0){
                required_count--;
            }
            mp[s[r]]--;
            
            while(required_count == 0){
                ws = r-l+1 ;
                if(ws<min_ws){
                    start_l = l ; // have to do this so that we can extract substring later
                    min_ws = ws ; 
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    required_count++;
                }
                l++;
            }
            r++;
        }

        if(min_ws == INT_MAX){
            return "";
        }

        return s.substr(start_l , min_ws) ;
    }   
};