class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m != n) return false ;
        // remember map to index not to frequency
        unordered_map<char ,int>mp1 ;
        unordered_map<char ,int>mp2 ;

        for(int i = 0 ; i<n ; i++){
            mp1[s[i]] = i;
        }

        for(int j = 0 ; j<n ; j++){
            mp2[t[j]] = j;
        }

        for(int k = 0 ; k<n ; k++){
            if(mp1[s[k]] != mp2[t[k]]) return false;
            
        }

        return true;
    }
};