class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        int n = nums.size();
        set<int>st ;
        int longestSeq = 0 ;
        int cnt = 0 ;

        for(int num : nums){
            st.insert(num);
        }
        // iterating the set

        for(auto it : st){
            if(st.find(it-1)==st.end()){
                cnt = 1 ; 
                int x = it ;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                longestSeq = max(longestSeq , cnt); 
            }
        }
        return longestSeq ;
    }
};