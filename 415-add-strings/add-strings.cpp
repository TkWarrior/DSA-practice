class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int digits1 = 0;
        int digits2 = 0;
        int carry = 0 ; 
        // failing on test cases like this "9333852702227987" and "85731737104263"
        // for(long long i = n1-1; i>=0; i--){
        //     digits1 = digits1 + (num1[i]-'0')*pow(10,n1-i-1);
        // }

        // for(long long  i = n2-1 ; i>=0 ; i--){
        //     digits2 = digits2 + (num2[i]-'0')*pow(10,n2-i-1);
        // }

        // res = digits1 + digits2;
        // string ans = "";

        // if(res == 0){
        //     return "0";
        // }
        // while(res>0){
        //     char c = (res%10) + '0';
        //     ans=c + ans;
        //     res = res/10;
        // }
        
        int i = n1-1 ; 
        int j = n2-1;
        int  sum = 0 ;
        string res = "";
        while(i>=0 || j>=0 || carry){
            digits1 = i>=0 ? num1[i--] - '0' : 0 ;
            digits2 = j>=0 ? num2[j--] - '0' : 0 ;
            sum = digits1 + digits2 + carry ;
            // char c = (sum%10) + '0';
            res = to_string((sum%10)) + res ; 
            carry = sum/10;
        }

        return res;
    }
};