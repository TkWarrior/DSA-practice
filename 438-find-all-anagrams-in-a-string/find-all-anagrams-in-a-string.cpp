class Solution {
public:
    bool allZero(vector<int>&mp){
        for(int i:mp){
            if(i!=0) return false;
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
       
       vector<int>mp(26,0);

        for(char c : p){
            mp[c-'a']++;
        }

        vector<int>res;
        int i = 0 ;
        int j = 0 ;

        while(j<s.length()){
            mp[s[j]-'a']--;

            if(j-i+1 == p.length()){
                if(allZero(mp)){
                    res.push_back(i);    
                }
                mp[s[i]-'a']++;
                i++;
            }
            j++;
        }

        return res;
    }
};