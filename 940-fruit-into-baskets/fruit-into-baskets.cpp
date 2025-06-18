class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //it is similar to finding maximum length of sliding window
        // means in sliding window we can only include two distinct element
      
      // Brute Force Time Complexity - O(N^2)
      // Space Complexity - O(1) since we are storing only 3 elements at the set
    //   int n = fruits.size();
    //   int max_len = 0;
    //   for(int i = 0 ; i<n ; i++){
    //         set<int>st;
    //         for(int j=i ; j<n ; j++){
    //             st.insert(fruits[j]);
    //             if(st.size()<=2){
    //                 max_len = max(max_len, j-i+1);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //     }
    //     return max_len;

        // Optimized Soln
        int n = fruits.size()  ;
        int l = 0 , r = 0;
        unordered_map<int,int>hashmap;
        int max_len = 0;
        while(r<n){
            hashmap[fruits[r]]++;
            if(hashmap.size()>2){
                while(hashmap.size()>2){        
                    hashmap[fruits[l]]--;
                    if(hashmap[fruits[l]]==0){
                        hashmap.erase(fruits[l]);
                    }
                    l++;
                  
                }
            }
            else{
                int len = r-l+1;
                max_len = max(max_len,len);
            }
            r++;
        }
        return max_len;
    }
};