class Solution {
public:
    // building LPS table
    void computeLPS(vector<int>&LPS ,string concatenatedString){
        LPS[0] = 0 ;
        int m = LPS.size();
        int length = 0 ;
        int i = 1 ;
        
        while(i<m){
            if(concatenatedString[i] == concatenatedString[length]){
                length++;
                LPS[i] = length ; 
                i++;
            }else{
                if(length!=0){
                    length = LPS[length-1];
                }else{
                    LPS[i] = 0 ;
                    i++;
                }           
            }
        }
    }
    string shortestPalindrome(string s) {
        // brute force

        // int n = s.size() ;
        // string t = s ;
        // reverse(t.begin() , t.end());
        // string res = "";

        // for(int i = 0 ; i<n ; i++){
        //     if(s.substr(0 , n-i) == t.substr(i)){
        //         return t.substr(0,i) + s;
        //     }
        // }

        // return t + s;
        
        string t = string(s.rbegin() , s.rend());
        // KMP Algo
        string concatenatedString = s + "#" + t;
        vector<int>LPS(concatenatedString.size());

        computeLPS(LPS , concatenatedString );

        int palindromeLength = LPS[concatenatedString.length()-1];

        string suffix = t.substr(0 ,s.length()-palindromeLength);

        return suffix + s ;


    }
};