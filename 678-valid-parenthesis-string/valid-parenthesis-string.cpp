class Solution {
public:
    int t[101][101];
    bool solve(int ind , int count ,  string&s){
        if(ind==s.size()){
            return count==0;      
        }
         if(t[ind][count] != -1){
            return t[ind][count];
        }
        bool isValid = false;
       
        if(s[ind]=='*'){
            // trying all the possiblity  or '*'='' or '*' = ')'
            //if '*' = '('
            isValid = isValid|solve(ind+1 , count+1 , s);
            //if '*' = ''
            isValid = isValid|solve(ind+1 , count , s);
            //if '*' = ')'
            if(count>0){
                isValid = isValid|solve(ind+1 , count-1 , s);
            }
        }
       else if(s[ind]=='('){
            // false or true will give true
            isValid = isValid|solve(ind+1 , count+1 , s);
       }
       else { // for the s[ind] = ')'
            if(count>0){
                 isValid = isValid|solve(ind+1 , count-1 , s);
            }
           
       }
      
        return t[ind][count] = isValid;
    }

    bool checkValidString(string s) {
       int count = 0 ; 
       memset(t,-1,sizeof(t));
       return solve(0 , count , s );
    }
};