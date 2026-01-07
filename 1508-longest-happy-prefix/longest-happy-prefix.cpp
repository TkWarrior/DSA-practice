class Solution {
public:

    void computeLPS(string s , int n , vector<int>&LPS){
        int i = 1 ;
        int length = 0 ; 
        LPS[0] = 0;

        while(i<n){
            if(s[i]==s[length]){
                length++;
                LPS[i] = length ;      
                i++ ;        
            }else{
                if(length>0){
                    length = LPS[length-1];
                    LPS[i] = length ;
                }else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }

    }

    string longestPrefix(string s) {
        int n = s.length();
        vector<int>LPS(n,0);
        if(n==1) return "";
        computeLPS(s , n , LPS);
        cout<<LPS[n-1];
        return s.substr(0 , LPS[n-1]);
    }
};