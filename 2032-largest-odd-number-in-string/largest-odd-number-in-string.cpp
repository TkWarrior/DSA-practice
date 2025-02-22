class Solution {
public:
    string largestOddNumber(string num) {
        // long long  num1 = stoi(num);
        // vector<int>arr;
        // while(num1!=0){
        //     arr.push_back(num1%10);
        //     num1 = num1/10;
        // }
        // // reverse(arr.begin(),arr.end());
        // string s = "";
        // int i;
        // for( i = num.length()-1 ; i>=0 ; i--){
        //     if(num[i]%2!=0){
        //         arr.push_back(num[i]-'0');
        //         s = s+to_string(arr[i]);
        //         break;
        //     }
        // }
        
        // for(int j = i-1; j>=0 ; j--){
        // //    s = s+to_string(arr[j]);
        //     arr.push_back(arr[j]);
        // }
        // reverse(arr.begin(),arr.end());
        // for(int k = 1 ; k<arr.size() ;k++){
        //     s = s+to_string(arr[k]);
        // }
        // return s;


        // this for loop is to find first odd number from backward this approach is giving me memory limit exceed now will solve it using optimised approach
        // for( i = num.length()-1 ; i>=0 ; i--){
        //     int n = num[i]-'0';
        //     if(n%2!=0){
        //         // arr.push_back(n);
        //         s = s+num[i];
        //         break;
        //     }
        // }
        
        // this for loop to add remaining number after finding 1st odd number
        // for(int j = i-1; j>=0 ; j--){
        //     s = num[j] + s;
            
        // }

        for(int i = num.length()-1 ;i>=0 ; i--){
            int n = num[i] - '0';
            if(n%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";

    }
};