class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u';
    }
    int solve(string&word , int k){
        
        int i = 0 , j = 0;
        int n = word.size();
        unordered_map<char,int>mp;
        int c = 0;

        while(j<n){
            if(!isVowel(word[j])){
                i = j+1;
                mp.clear();
                j++;
                continue;
            }
            mp[word[j]]++;
            while(mp.size()>k){
                mp[word[i]]--;
                if(mp[word[i]]==0){
                    mp.erase(word[i]);
                }
                i++;
            }
            c =  c + (j-i+1);
            j++;
        }

        return c;
    }
    int countVowelSubstrings(string word) {
        
        return solve(word , 5) - solve(word , 4);
    }
};