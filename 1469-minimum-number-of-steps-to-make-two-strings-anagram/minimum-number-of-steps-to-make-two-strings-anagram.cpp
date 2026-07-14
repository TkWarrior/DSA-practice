class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<char,int>mp;
        int sum = 0;

        for(char c : s){
            mp[c]++;
        }

        for(char c : t){
            mp[c]--;
        }

        for(auto it :mp){
            if(it.second>0){
                sum += it.second;
            }
        }

        return abs(sum) ;

    }
};