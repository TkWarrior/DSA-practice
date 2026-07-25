class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        st.push(height[0]);
        int n = height.size();
        int max_height = height[0] ;
        int ind = 0 ;
        int water = 0 ;

        for(int i = 1 ; i<n ;i++){
            if(height[i]>max_height){
                max_height = height[i];
                ind = i;
            }
        }
        
        for(int i = 1 ; i<ind ; i++){
            if(height[i]>st.top()){
                st.pop();
                st.push(height[i]);
            }else{
                water += (st.top()-height[i]);
            }
        }
       
        cout<<st.top();
        st.pop();

        st.push(height[n-1]);
      
        for(int i = n-1 ; i>ind ; i--){
            if(height[i]>st.top()){
                st.pop();
                st.push(height[i]);
            }else{
                
                water += (st.top()-height[i]);
            }
        }

        return water ;
    }
};