class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // just random hit and trial able to pass sample test case but not all test cases due to limited knowledge
        // int n = intervals.size();
       
        // vector<vector<int>>ans;
        // vector<int>temp;
        // sort(intervals.begin(),intervals.end());
        // int i=0,j=i+1;
        
        // if(n==1){
        //     temp = {intervals[i][0],intervals[i][1]};
        //     ans.push_back(temp);
        //     return ans;
        // }

        // if(n==2){
        //     if(intervals[i][1]>=intervals[j][0]){
        //         if(intervals[i][1]>=intervals[j][1]) temp = {intervals[i][0],intervals[i][1]};
        //         else temp = {intervals[i][0],intervals[j][1]};
        //         ans.push_back(temp);
               
        //     }
        //     else{
        //         temp = {intervals[i][0],intervals[i][1]};
        //         vector<int>temp1 = {intervals[j][0],intervals[j][1]};
        //         ans.push_back(temp);        
        //         ans.push_back(temp1);
                  
        //     }
        //    return ans;
        // }
        // while(i<n && j<n){
           
        //     if(intervals[i][1]>=intervals[j][0]){
        //         if(intervals[i][1]>=intervals[j][1]) temp = {intervals[i][0],intervals[i][1]};
        //         else temp = {intervals[i][0],intervals[j][1]};
        //         // temp = {intervals[i][0],intervals[j][1]};
        //         ans.push_back(temp);
        //         intervals[i][1] = ans[i][1];
        //         j++;
        //     }
        //     else{
        //         temp = {intervals[j][0],intervals[j][1]};
        //         ans.push_back(temp);
        //         i = j;
        //         j = i+1;
        //     }
        // }
        
        // return ans;
        
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i = 0 ; i<n ; i++){
            // if ans is empty for ex if ans is not empty aur ek case [1,3] && [8,10] ka toh agar 8>3 se toh that interval [8,10] jo ki intervals[i] will be push back to the ans 
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
// in this scenario agar [1,3] && [2,6] 3>2 which is ans.back()[1]>intervals[i][0] toh iss case 3 will be updated to 6 and ans will be [1,6]
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};