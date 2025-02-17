class Solution {
public:
    // this function is too reverse the words coming from s2
    string reverseString(string &str){
        int i = 0,j=str.length()-1;
        while(i<j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
        return str;
    }
    string reverseWords(string s) {
       string s1 = "";
       string s2 = "";
       string s3 = "";
       // this is too store the reverse character
       for(int i = s.length()-1 ; i>=0 ; i--){    
            s1 = s1+s[i];  
       }
       
       // this is loop is to store the reverse word
       for(int j = 0 ; j<s1.length() ;j++){
        
            if(s1[j]!=' '){
               s2 = s2+s1[j]; 
            }
            if(s1[j]==' ' || j==s1.length()-1){
                s3 =s3+reverseString(s2)+" ";
                s2 = "";
            }
       }

      //this loop is too remove empty characters and remove multiple spaces

       for(int k = 0 ;k<s3.length() ; k++){
            //for removing initial empty characters
            if(s3[0]==' ' ){
                s3.erase(s3.begin()+0);
            }
            // for removing final empty characters
            if(s3[s3.length()-1]==' ' ){
                s3.erase(s3.begin()+s3.length()-1);
            }

            if(s3[k] == ' ' && s3[k+1]==' '){
                s3.erase(s3.begin()+k);
                k--;
            }
       }
      
       return s3;
    }
};