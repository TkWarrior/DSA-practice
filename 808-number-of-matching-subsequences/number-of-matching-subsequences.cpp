class Solution {
public:
    bool solve(string&s ,string&t ,map<char , vector<int>>&mp){
        // int m = s.size();
        int n = t.size();
        int prev = -1;
        
        for(int i = 0 ; i<n ; i++){
            if(mp.find(t[i])==mp.end()){
                return false;
            }
            vector<int>&ind = mp[t[i]];
            auto it = upper_bound(begin(ind),end(ind),prev);

            if(it==ind.end()){
                return false;
            }
            prev = *it;
                 
        }

        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        map<char , vector<int>>mp ;
        int m = s.size();

        for(int i = 0 ; i<m ; i++){
            mp[s[i]].push_back(i);
        }

        int size = words.size();

        for(int i = 0 ; i<size ; i++){
            if(solve(s , words[i], mp)){
                cnt++;
            }
        }

        return cnt;
    }
};