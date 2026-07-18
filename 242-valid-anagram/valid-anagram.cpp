class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();

        vector<int>freq1(26);
        vector<int>freq2(26);

        for(char ch : s){
            freq1[ch-'a']++;
        }

        for(char ch : t){
            freq2[ch-'a']++;
        }

        if(freq1==freq2){
            return true;
        }

        return false;
    }
};