class Solution {
public:
    bool allZero( vector<int>&mp){

        for(int i:mp){
            if(i!=0){
                return false;
            }
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();

        if(m<n) return {};

        vector<int>ans ;
        
        int i = 0 ;
        int j = 0 ;
        vector<int>mp(26,0);

        for(char ch : p){
            mp[ch-'a']++;
        }

        while(j<m){
            char ch = s[j];
            mp[ch-'a']--;
            
            if(j-i+1==n){
                if(allZero(mp)){
                    ans.push_back(i);
                }
                mp[s[i]-'a']++;
                i++;
            }
            j++;
        }

        return ans;
    }
};