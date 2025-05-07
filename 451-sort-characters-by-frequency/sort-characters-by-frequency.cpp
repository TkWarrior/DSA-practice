class Solution {
public:
    // typedef pair<char,int>P;
    string frequencySort(string s) {
        // learnt about lambda - in  this problem it is used for custom sorting 
        // vector mein pair bhi store kara sakte hai like in this case we have used the pair of character and its frequency inside the vector
        // vector<pair<char,int>>>vec(123)
        vector<pair<char,int>>vec(123);
        string result = "";
        for(char &ch : s){
            int freq = vec[ch].second;
            vec[ch] = {ch,freq+1};
        }

        auto lambda = [&](pair<char,int> & p1,pair<char,int> & p2){
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