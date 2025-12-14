class Solution {
public:
    int helper(int num){
        int sum = 0 ;
        while(num>0){
            sum += num%10 ;
            num = num/10;
        }

        return sum ; 
    }
    int differenceOfSum(vector<int>& nums) {
        int ele_sum = 0 ;
        int dig_sum = 0 ;

        for(int num : nums){
            ele_sum += num ; 
            dig_sum += helper(num);
        }

        return abs(ele_sum - dig_sum);
    }
};