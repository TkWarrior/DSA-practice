class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int>mp(26);
        int sum = 0;

        for(char c : s){
            mp[c-'a']++;
        }

        for(char c : t){
            mp[c-'a']--;
        }

        for(int i = 0 ; i<26 ; i++){
            if(mp[i]>0){
                sum += mp[i];
            }
            
        }

        return abs(sum) ;

    }
};