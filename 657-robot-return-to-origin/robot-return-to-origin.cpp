class Solution {
public:
    bool judgeCircle(string moves) {
        stack<char>st ;
        

        int count1 = 0 ;
        int count2 = 0 ;
        for(char c : moves){
           if(c=='L') count1++;
           if(c=='R') count1--;
           if(c=='U') count2++;
           if(c=='D') count2--;
        }
        return count1==0 && count2==0;
    }
};