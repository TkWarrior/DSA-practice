class Solution {
public:
    string frequencySort(string s) {
       typedef pair<char , int>P ; 
       vector<P>vec(123) ; 

        for(char&ch :s){
            int freq = vec[ch].second;
            vec[ch] = {ch , freq+1};
        }

        sort(vec.begin() , vec.end() ,[&](P & p1 , P & p2){
            return p1.second > p2.second ;
        });
        string res = "";

        for(int i = 0 ; i<123 ; i++){
            if(vec[i].second > 0){
                int freq = vec[i].second ; 
                char ch = vec[i].first; 
                res += string(freq , ch);
            }       
        }

        return res ;
    }
};