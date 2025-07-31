class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int farthest = 0 ;
        int max_jump = 0 ;

        for(int i = 0 ; i < nums.size() ; i++){
            if(i > max_jump ) return false; // catch [3,2,1,0,4] for the test cases ike this
            farthest = i+nums[i];
            max_jump = max(farthest , max_jump);
        }
       
        return true;
    }
};