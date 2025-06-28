class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start_l = 0;
        int count_required = n;
       
        unordered_map<char, int> hashmap;
        if (n > m) {
            return "";
        }

        for (int i = 0; i < n; i++) {
            hashmap[t[i]]++;
        }

        while (r < m) {

            if(hashmap[s[r]]>0){
                count_required--;
            }
            
            hashmap[s[r]]--;
            // as soon count_required becomes start shrinking the window
            while (count_required == 0) {

                if(min_len > r-l+1){
                    min_len = r-l+1;
                     start_l = l;
                }
               
                hashmap[s[l]]++;
                // if the frequency becomes greater than 0
                if (hashmap[s[l]] > 0) {
                    count_required++;
                }
                l++;
            }
            r++;
        }
       
       return min_len == INT_MAX ? "" : s.substr(start_l,min_len);
    }
};