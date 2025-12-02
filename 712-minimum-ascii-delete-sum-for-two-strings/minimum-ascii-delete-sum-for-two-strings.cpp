class Solution {
public:
    int dp[1001][1001];
    int ascii_sum_calc(string&s){
        int sum = 0 ;

        for(char ch : s){
            sum += ch - 'a' + 97 ;
        }

        return sum ;
    }
    int solve(string & s1 , string &s2 , int m , int n ){
        if(m==0 || n==0 ){
            return  0;
        }
        if(dp[m][n]!=-1) return dp[m][n] ; 
        if(s1[m-1]==s2[n-1]){
            return dp[m][n] = (s1[m-1] - 'a' + 97) + solve(s1 , s2 , m-1 ,n-1);
        }
   
        return dp[m][n] = max(solve(s1 ,s2 , m-1 , n) , solve(s1,s2 ,m , n-1));
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size() ; 
        int n = s2.size() ;
        memset(dp , -1 , sizeof(dp));
        int lcs = solve(s1 , s2 , m , n);
        string res = "";
        
        int i = m , j = n ; 

        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                res.push_back(s1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){     
                    i--;
                }else{
                    j--;
                }
            }
        }
        reverse(res.begin() ,res.end());
        cout<<res;
        int ascii_s1 = ascii_sum_calc(s1); 
        int ascii_s2 = ascii_sum_calc(s2); 
        int ascii_lcs_sum = ascii_sum_calc(res);

        return ascii_s1 + ascii_s2 - 2*ascii_lcs_sum;
    }
};