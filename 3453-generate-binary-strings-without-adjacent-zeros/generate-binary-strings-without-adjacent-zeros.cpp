class Solution {
public:
    vector<string>binaryArr;
    string substring = "";
    void solve( int n ,  string&substring , vector<string>&binaryArr){
        if(n==0){
            binaryArr.push_back(substring);
            return;
        }
        
        if(substring.empty() || substring.back()=='1'){
            substring.push_back('0');
            solve(n-1 ,substring , binaryArr);
            substring.pop_back();
        }
        substring.push_back('1');
        solve(n-1 , substring ,binaryArr);
        substring.pop_back();
        
        
  
    }
    vector<string> validStrings(int n) {
        solve(n , substring , binaryArr);
        return binaryArr;
    }
};