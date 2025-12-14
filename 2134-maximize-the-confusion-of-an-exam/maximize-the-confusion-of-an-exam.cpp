class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size() ; 
        int maxi1 = 0 ;
        int l = 0 ,r = 0 ;
        int new_k = k ; 
        while(r<n){
            if(answerKey[r]=='F'){
                k--;
            }
            while(k<0){
                if(answerKey[l] == 'F'){
                    k++;
                }
                l++;
            }
            maxi1 = max(maxi1 , r-l+1);   
            r++;
        }
        k = new_k ; 
        l = 0 , r = 0;
        int maxi2 = 0 ;
        while(r<n){
            if(answerKey[r]=='T'){
                k--;
            }
            while(k<0){
                if(answerKey[l] == 'T'){
                    k++;
                }
                l++;
            }
            maxi2 = max(maxi2 , r-l+1);   
            r++;
        }
       
        return max(maxi1 , maxi2) ;
    }
};