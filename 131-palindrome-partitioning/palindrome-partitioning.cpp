class Solution {
public:
    bool isPalindrome(string s ,int start , int end ){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int ind ,string s , vector<string>&res , vector<vector<string>>&ans){
       if(ind == s.size()){
            ans.push_back(res);
       }
      
       for(int i = ind ; i<s.size() ; i++){
            if(isPalindrome(s, ind , i)){
                 res.push_back(s.substr(ind , i-ind+1));
                 solve(i+1 , s , res, ans);
                 res.pop_back();
            }     
       }        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res ;   
        solve(0,s ,  res , ans) ; 
        return ans;
    }
};