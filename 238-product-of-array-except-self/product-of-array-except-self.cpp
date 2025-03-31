class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    //Brute force
    //     vector<int>ans;
    //     int curr_prod = 1;
    //     int n = nums.size();
    //     for(int i = 0 ; i<n ; i++){
    //         curr_prod = 1;
    //         for(int j = 0 ; j<n ; j++){
    //             if(j==i) continue;
    //             curr_prod = curr_prod*nums[j];
    //         }
    //         ans.push_back(curr_prod);
    //     }
    // return ans;

    //Optimal
    int n = nums.size();
    vector<int>left_prod(n);
    vector<int>right_prod(n);
   
    int prod = 1;
    //for left_prod array
    left_prod[0] = 1;
    // [1,1,2,6]
    // [1*1 , 1*1,2*1,2*3]
    
    for(int i = 1 ; i<n ; i++){
        prod = nums[i-1]*left_prod[i-1];
        left_prod[i] = prod;
    }
    
    // for right_prod array
    // [24,12,4,1]
    // [ 12*2,4*3 , 1*4,1]
    
    right_prod[n-1] = 1;
    prod = 1;

    for(int i = n-2 ; i>=0 ; i--){
        prod = nums[i+1]*right_prod[i+1];
        right_prod[i] = prod;
    }

    vector<int>ans(n);
    for(int i = 0; i<n ; i++){
        ans[i] =  left_prod[i]*right_prod[i];

    }
    return ans;
    }
};