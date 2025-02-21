class Solution {
public:
    string removeOuterParentheses(string s) {
        string s1 = "";

        int count = 0 ;
        vector<string>v1;
        for(int i = 0 ; i<s.length() ; i++){
            s1 = s1+s[i];
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                v1.push_back(s1);
                s1 = "";
            }
        }

        string s2 = "";
        for(int j = 0 ; j<v1.size() ; j++){
            v1[j].erase(v1[j].begin());
            v1[j].erase(v1[j].end()-1);
            s2 =  s2+v1[j] ;
        }
        return s2;
    }
};