class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int lc = 0;
       int n = nums.size();
       unordered_set<int>st ;
        int cnt = 0 ;
       for(int num:nums){
            st.insert(num);
       }

       for(auto it:st){
            if(st.find(it-1)==st.end()){
                int x = it;
                cnt = 1;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                 lc = max(lc,cnt);
            }
       }

       return lc ;
    }
};