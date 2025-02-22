class Solution {
public:
    bool rotateString(string s, string goal) {
       
        vector<string>v1;
        int n = s.length();
        string s1(n,' ');
        for(int i = 0 ; i<n ; i++){
            string s1(n,' ');
            for(int j = 0 ; j<n ; j++){
                
                s1[(j+i)%n]= s[j];
            }
            v1.push_back(s1);
        }
        for(int i =0 ; i<v1.size() ;i++){
            if((v1[i].compare(goal))==0){
                return true;
            }
        }
        return false;
       
    }
};