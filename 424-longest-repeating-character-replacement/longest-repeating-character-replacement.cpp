class Solution {
public:
    int characterReplacement(string s, int k) {

        //Brute force
        // int max_len = 0;
        // int len = 0;
        // int n = s.length();
        // int max_freq = 0;
        // for(int i = 0 ; i<n ; i++){
        //     max_freq = 0 ;
        //     int hash[26] = {};
        //     for(int j = i ; j<n ; j++){
        //         hash[s[j]-'A']++;
        //         max_freq = max(max_freq,hash[s[j]-'A']);
        //         len = j-i+1;
        //         //no of conversions we have to do
        //         int conversions = len - max_freq;
        //         if(conversions<=k){
        //             max_len = max(max_len,len);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return max_len;

        /* Size of the window will be the no of conversions <= k
        if it is greater than k then we will trim down the window size from the left
        */
        int l = 0 , r = 0;
        int max_len = 0;
        int n = s.length();
        unordered_map<int,int>hashmap;
        int max_freq = 0;
        while(r<n){
            hashmap[s[r]-'A']++;
            max_freq = max(max_freq,hashmap[s[r]-'A']);
            while((r-l+1)-max_freq > k){
               hashmap[s[l]-'A']--;
               max_freq = 0;
                for(int i = 0 ; i<26 ; i++) {
                    max_freq = max(max_freq,hashmap[i]);
                }
                l++;
            }
            if((r-l+1)-max_freq<=k){
                max_len = max(max_len,(r-l+1));
            }
            r++;
        }
        return max_len;
    }
};