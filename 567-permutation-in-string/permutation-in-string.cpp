class Solution {
public:
   
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(char ch : s1){
            freq1[ch-'a']++;
        }

        int l = 0 ;
        int r = 0 ;
        int k = s1.size(); // window size
        int n = s2.size();

        while(r<n){
            freq2[s2[r]-'a']++;

            if(r-l+1>k){
                freq2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==k){
                 if(freq1 == freq2){
                    return true;
                }
            }
           
            r++;
        }
        return false ;
    }
};