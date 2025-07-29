class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // first sort the bills;
       
        int n = bills.size();
        int count_five = 0 ;
        int count_ten = 0 ;
        int count_twenty = 0 ;

        for(int i = 0 ; i<n ; i++){  
            if(bills[i]==5){
                count_five++;
            }else if(bills[i]==10){
                if(count_five){
                    count_five--;
                }else{
                    return false;
                }
                count_ten++;
               
            }else{
                if(count_ten && count_five){
                    count_ten--;
                    count_five--;
                }
                else if(count_five>=3){
                    count_five = count_five-3;
                }else{
                    return false;
                }
                count_twenty++;
            }
            
          
        }
       return true;
    }
};