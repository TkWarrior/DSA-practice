class Solution {
public:
    string addBinary(string a, string b) {
       int i = 0 ; 
       int alen = a.length();
       int blen = b.length();
       string ans = "";
       int sum = 0 ;
        
       int carry = 0;

        while( i<alen || i<blen || carry!=0){
            sum = carry;
            if(i<alen){
                sum+=a[alen-i-1]-'0';
            }
            if(i<blen){
                sum+=b[blen-i-1]-'0';
            }
           
            int val = sum%2;
            ans = to_string(val) + ans;
            carry = sum/2;
            i++;
        }

        return ans;
    }
};