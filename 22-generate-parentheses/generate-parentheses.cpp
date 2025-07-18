class Solution {
public:
    vector<string>ans; 
    bool isValid(string&result){
        int count = 0 ;
        for(char&ch:result){
            if(count<0){
                return false;
            }
            if(ch=='('){
                count++;
            }
            else{
                count--;
            }

        }
        if(count == 0){
            return true;
        }
        return false;
    }
    
    void solve(string&result , int n){
        if(result.size()==2*n){
            if (isValid(result)){
               ans.push_back(result);
            }
          return ; 
        }

        // take '('
        result.push_back('(');
        solve(result , n );
        result.pop_back() ; 

        // take ')'
        result.push_back(')');
        solve( result , n);
        result.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        
        string result = "";
        solve(result , n );
        return ans;
    }
};