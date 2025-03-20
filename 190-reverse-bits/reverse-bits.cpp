class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int lsb;
        int reverselsb;
        for(int i = 0 ; i<32 ; i++){
            lsb = n&1; // first we have taken and & with 1 to calculate least significant bit 

            reverselsb = (lsb<<(31-i));//after that we have done left shift by 31-i times for i = 0 its 31 times
            ans = ans|reverselsb;//after that we have taken the OR with ans
            n = n>>1; // every we right shift the bit by one 
        }
        return ans;
    }
};