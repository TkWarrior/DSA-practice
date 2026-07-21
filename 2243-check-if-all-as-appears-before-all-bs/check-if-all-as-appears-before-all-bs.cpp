class Solution {
public:
    bool checkString(string s) {
        int i = 0 ;

        while(s[i]=='a'){
            i++;
        }

        int n = s.length();

        while(i<n){
            if(s[i]=='a') return false;
            i++;
        }

        return true;
    }
};