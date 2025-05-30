class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Initial thought process
        // vector<int>temp;
        // unordered_map<int,int>umap;
        // int n = nums.size();
        // int new_size = 2*n;
        // for(int i = 0 ; i<new_size-1 ; i++){
        //     int j = (n+i)%n;
        //     temp.push_back(nums[j]);
        // }
        // stack<int>st;
        // vector<int>ans;
        // for(int j = temp.size()-1 ; j>=0 ; j--){
        //     while(!st.empty() && st.top()<=temp[j]){
        //         st.pop();
        //     }
        //     if(st.empty()){
        //         umap[temp[j]] = -1;
        //     } 
        //     else{
        //         if(umap.find(temp[j])==umap.end() && umap[temp[j]]<=st.top()){
        //              umap[temp[j]] = st.top();
        //         }
        //         else{
        //             umap[temp[j]] = st.top();
        //         }
        //     }
        //     st.push(temp[j]);
        // }
        // for(int i = 0 ; i<n ; i++){
        //    ans.push_back(umap[nums[i]]);
        // }
        // return ans;

        //brute force approach
        // int n = nums.size();
        // vector<int>nge(n,-1);
         
        //  for(int i = 0 ; i<n ; i++){
        //     for(int j = i+1 ; j<i+n ; j++){
        //         int idx = (j%n);
        //         if(nums[idx]>nums[i]){
        //             nge[i] = nums[idx];
        //             break;
        //         }
        //     }
        //  }
        //  return nge;

        //Optimal soln
        stack<int>st;
        int n =  nums.size();
        vector<int>ans(n);

        for(int i = 2*n ; i>=0 ; i--){
            int idx = (n+i)%n;
            while(!st.empty() && st.top()<=nums[idx]){
                st.pop();
            }
            if(i<n){
                if(st.empty() ){
                    ans[i] = -1;
                }
                else {
                    ans[i] = st.top();
                }
            }
            st.push(nums[idx]);          
        }
        return ans;
    }
};