class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.length();
        int n = typed.length() ;
        int i = 0 ; 
        int j = 0 ;

        while(i<m && j<n){
            if(name[i]==typed[j]){
                i++;
                j++;
            }else if(i>0 && name[i-1]==typed[j]){
                j++ ;
            }else{
                return false ;
            }
        }

        if(i<m){
            return false ;
        }
        while(j<n){
            if(name[i-1]==typed[j]){
                j++;
            }else{
                return false;
            }
        }

        return true ;
    }
};