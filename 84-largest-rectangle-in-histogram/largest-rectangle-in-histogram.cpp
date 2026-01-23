class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int nse[n];
        int pse[n];
        stack<int>st;
        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
         //clearing stack so that it get used by below funtion
        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        } 
     
        int max_area = 0;
        for(int i = 0 ; i<n ; i++){
            int width = nse[i] - pse[i] -1;
            int area = heights[i]*width;
            max_area = max(max_area,area);
        }
     return max_area;
    }
};