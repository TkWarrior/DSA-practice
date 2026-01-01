class Solution {
public:
    int minAllOneMultiple(int k) {
        long long rem = 1 ;
        int c = 1 ;
    
        if(k%2==0 || k%5==0){
            return -1 ;
        }
        unordered_set<int>st;
        st.insert(rem);

        while(rem%k!=0){
            rem = (rem*10 +1)%k;
            c++;  
            // if remainder repeated then return -1
            if(st.find(rem)!=st.end()){
                return -1 ;
            }

            st.insert(rem);
        }

        return c ;
        
    }
};