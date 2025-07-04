class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // question of moore's voting algorithm

        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        
        int maj1 = INT_MIN;
        int maj2 = INT_MIN;
        vector<int>res;

        for(int i= 0 ; i<n ; i++){
            if(nums[i]==maj1){
                count1++;
            }
            else if(nums[i]==maj2){
                count2++;
            }
            else if(count1==0){
                count1 = 1;
                maj1 = nums[i];
            }
            else if(count2==0){
                count2 = 1;
                maj2 = nums[i];
            }
            else {
                count1--;
                count2--;
            }
        }

        int freq1 = 0;
        int freq2 = 0;
        
        for(int i = 0 ; i<n ; i++){
            if(nums[i]==maj1){
                freq1++;
            }
            else if(nums[i]==maj2){
                freq2++;
            }
        }

        //verification
        if(freq1 > n/3 ){
            res.push_back(maj1);
        }
        
        if(freq2 > n/3 && maj1!=maj2){
            res.push_back(maj2);
        }

        return res;
    }
};