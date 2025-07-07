class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int idx = 0 ;
        int res = 0;
        
        while(s[idx]==' '){
           
            idx++;
        }
        
        if(s[idx] == '-' || s[idx] == '+'){
            
            if(s[idx] == '-'){
                sign = -1;
            }
           
            idx++;
        }
        
        while(s[idx]>='0' && s[idx]<='9'){
            // Boundary condition 
            
            if(res>INT_MAX/10 || (res==INT_MAX/10 && s[idx]-'0'> 7)){
           
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            res = res*10 + (s[idx] - '0');
     
            
            
            idx++;
        }
        
        int final_val = res*sign;
        
        return final_val;
    }
};