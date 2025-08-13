class Solution {
public:
    bool isAnagram(string s, string t) {
        
       map<char , int>mp1; 
       map<char , int>mp2;
       
        if(s.length()!=t.length()) return false;

       for(int i = 0 ; i<s.length() ; i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
       }

       for(int i = 0 ; i<s.length() ; i++){
            if(mp1[s[i]] != mp2[s[i]]){
                return false;
            }
       }

       return true;
    }
};