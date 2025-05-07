class Solution {
public:
    typedef pair<char,int>P;
    string frequencySort(string s) {
        
        vector<P>vec(123);
        string result = "";
        for(char &ch : s){
            int freq = vec[ch].second;
            vec[ch] = {ch,freq+1};
        }

        auto lambda = [&](P & p1,P & p2){
            return p1.second>p2.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        
        for(int i = 0 ; i<123 ; i++){
            if(vec[i].second>0){
                char ch = vec[i].first;
                int freq = vec[i].second;
                string temp = string(freq,ch);
                result += temp;
            }
        }

        return result;
        // int count = 0;
        // int i = 0 ;
        // string s1 = "";
        // int maxi = -1;
        // while(i<s.length()){
        //     if(s[i]==s[i+1]){
        //         count++;
        //     }
        //     maxi = max(count,maxi);
        //     if(count>maxi){
               
        //         s1 = s1 + s[i];
        //     }
        //     else{
        //         s1 = s[i] + s1;
        //     }
        //     i++;
        // }
        
        // return s1;
    }
};