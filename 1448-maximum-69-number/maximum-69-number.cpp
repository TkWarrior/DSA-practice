class Solution {
public:
    int maximum69Number (int num) {
        int max_num = 0;
        vector<int>res;
        int rem = 0;

        while(num>0){
           
            rem = num%10;
            res.push_back(rem);
            num = num/10 ;
        
        }

        reverse(res.begin() , res.end());

        for(int i = 0 ; i<res.size() ; i++){          
            if(res[i] == 6){
                res[i] = 9;
                break;
            }
        }

        for(int i : res){
              max_num = max_num*10 + i;
        }
        return max_num;
    }
};