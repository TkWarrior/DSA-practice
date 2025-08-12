class Solution {
public:
    
    bool isPalindrome(string a){
       
        string temp  = "";
        for(int i = 0 ; i<a.length() ; i++){
            
            if(a[i]>='A' && a[i]<='Z'){
                a[i] = a[i]+32;
                temp.push_back(a[i]);
            }else if((a[i]>='a' && a[i]<='z') || (a[i]>='0' && a[i]<='9')){
                temp.push_back(a[i]);
            }else{
                continue;
            }
        }
        
        int s = 0 ; 
        int e = temp.length()-1;
       
        while(s<=e){
            if(temp[s]!=temp[e]){
               return false; 
            }
            s++;
            e--;
        }
       
        return true;
    }
        
    
};