class Solution {
public:
    int largestAreaInHistogram(vector<int>&heights){
        stack<int>st;
        int n = heights.size();
        vector<int>pse(n) ;
        vector<int>nse(n) ;
        //previous smaller element
        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            // if(st.empty()){
            //     pse.push_back(-1);
            // }
            // else{
            //     pse.push_back(st.top());
            // }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        //clearing stack
        while(!st.empty()){
            st.pop();
        }
        // next smaller element
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            // if(st.empty()){
            //     nse.push_back(n);
            // }
            // else{
            //     nse.push_back(st.top());
            // }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int max_hist_area = 0 ;
        for(int i = 0 ; i<n ; i++){
            int width = nse[i]-pse[i]-1;
            int area = heights[i]*width;
            max_hist_area = max(max_hist_area,area);
        }
        return max_hist_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // first convert character to int
        int n = matrix.size(); // no of rows
        int m = matrix[0].size() ;// no of coloumns
        vector<vector<int>>prefix(n,vector<int>(m,0));

        for(int i = 0 ; i<m ; i++){
            int sum = 0 ;
            for(int j = 0 ; j<n ; j++){
                if(matrix[j][i]=='0'){
                    sum = 0;
                } 
                else{
                    sum+=(matrix[j][i]-'0');
                }
                prefix[j][i] = sum;
            }
        }
        int max_area = 0;

        for(int i = 0 ; i<n ; i++){
            max_area = max(max_area , largestAreaInHistogram(prefix[i]));    
        }
        return max_area;
    }
};