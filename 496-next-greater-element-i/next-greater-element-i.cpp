class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        // better optimized solution using hashmap and stack 
        unordered_map<int,int>umap;
        vector<int>result;
        stack<int>st;
        // inititally we're storing -1 value to the corresponding keys 
        for(int i = 0 ; i<nums1.size() ; i++){
            umap[nums1[i]] = -1;
        }
       
        for(int j = nums2.size()-1 ; j>=0 ; j--){
            while(!st.empty() && st.top()<=nums2[j]){
                st.pop();
            }
            if(st.empty()){
                umap[nums2[j]] = -1;
            }
            else{
                umap[nums2[j]] = st.top();
            }
            st.push(nums2[j]);
        }
        
        for(int i = 0 ; i<nums1.size() ; i++){
            result.push_back(umap[nums1[i]]);
        }
        return result;
    }
};