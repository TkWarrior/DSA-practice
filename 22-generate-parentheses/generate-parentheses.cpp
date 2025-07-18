class Solution {
public:
    vector<string>ans; 
    // approach-1 
    // bool isValid(string&result){
    //     int count = 0 ;
    //     stach<char>st;
    //     for(char&ch:result){
    //         if(count<0){
    //             return false;
    //         }
    //         if(ch=='('){
    //             count++;
    //         }
    //         else{
    //             count--;
    //         }

    //     }
    //     if(count == 0){
    //         return true;
    //     }
    //     return false;
    // }
    
    // appraoch -2 liitle bit efficient  than the 1st approach
    void solve(string&result , int n,int open , int close){
        if(result.size()==2*n){
               ans.push_back(result);
          return ; 
        }

        // take '('
        // just added the safety check 
        //intuion open bracket '( 'n' se zyada nhi ho sakte in a balanced parenthesis
       
        if(open<n){
             result.push_back('(');
             solve(result , n ,open+1 ,close);
             result.pop_back() ;
        }
        

        // take ')'
        // close bracket ko tab tak add karna hai jab tak wo 'n' se kam ho
         if(close<open){
            result.push_back(')');
            solve( result , n , open , close+1);
            result.pop_back();
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        int open = 0 ;
        int close = 0 ;
        string result = "";
        solve(result , n ,open , close);
        return ans;
    }
};