class Solution {
public:
   
   
    string reverseWords(string s) {
        int l = 0 ;
        int r = 0 ;

        int i = 0 ;
        int n = s.size();
        reverse(s.begin() , s.end());

        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i==n) break ;
            while(i<n && s[i]!= ' '){
                s[r++] = s[i++];
            }
            reverse(s.begin()+l , s.begin()+r);
            s[r++] = ' ';
            l = r ;
            i++ ;
        }

        s.resize(r-1);

        return s ;
    }
};