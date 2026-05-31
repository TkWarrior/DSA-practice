class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        map<char , vector<int>>mp;
        int m = s.size();
        int n = t.size();

        for(int i = 0 ; i<n ; i++){
            mp[t[i]].push_back(i);
        }

        int prev = -1;

        for(int i = 0 ; i<m ; i++){
            
            if(mp.find(s[i])==mp.end()){
                return false;
            }

            vector<int>ind = mp[s[i]];
            auto it = upper_bound(begin(ind) , end(ind) ,prev);

            if(it == ind.end()){
                return false;
            }
            prev = *it;
        }

        return true;
    }
};