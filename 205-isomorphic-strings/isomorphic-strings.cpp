class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>umap;
        unordered_map<char,int>umap1;
        for(int i=0 ; i<s.length(); i++){
            umap[s[i]] = i;
            umap1[t[i]] = i;
        }
        for(int j = 0 ; j<s.length() ; j++){
            if(umap[s[j]] != umap1[t[j]]){
                return false;
            } 
        }
        return true;
    }
};