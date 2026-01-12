class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int hash[100000] = {0};
        int cnt = 0 ;
        int maxi = 0 ;
        unordered_set<int>st ;

        for(int num : nums){
            st.insert(num);
        }

        for(auto it :st){
            if(st.find(it-1)==st.end()){
                cnt = 1 ;
                int x = it ;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                maxi = max(maxi ,cnt); // storinf longest consequence sequence
            }
        }

        return maxi ;
    }
};