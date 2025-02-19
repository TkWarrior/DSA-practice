class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        int n = digits.size();
        for(i = n-1 ; i>=0; i--){
            if(digits[i]<9){
                digits[i] = digits[i] + 1;
                return digits;
            }
           else
           {
                digits[i] = 0;
           }
        }
        vector<int>ans(n+1);
        ans[0] = 1;
        
        return ans;
    }
};