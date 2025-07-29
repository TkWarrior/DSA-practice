class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0 ; 
        int r = 0 ; 
        int count = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(l<g.size() && r<s.size()){
            if(s[r]>=g[l]){
                count++;
                l++;  
            }
            r++;
        }
        return count;
    }
};