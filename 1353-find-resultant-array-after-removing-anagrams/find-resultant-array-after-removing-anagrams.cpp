class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans ;

        ans.push_back(words[0]);

        for(int i = 1 ; i<words.size() ; i++){
            string a = words[i];
            sort(a.begin(),a.end());
            string b = ans.back();
            sort(b.begin(),b.end());
            if(a!=b){
                ans.push_back(words[i]);
            }
        }

        return ans;

       
    }
};