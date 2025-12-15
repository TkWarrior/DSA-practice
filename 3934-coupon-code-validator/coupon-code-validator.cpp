class Solution {
public:

    bool isValid(string&code){
        if(code.empty()){
            return false;
        }
        for(char&ch : code){
            if(!isalnum(ch) && ch !='_'){
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int>umap = {
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        } ; // store valid coupns along with the businessLine in the umap;
        vector<pair<int,string>>temp ; 
        int n = code.size();
        
        for(int i = 0 ; i<n ; i++){
            if(isActive[i] && umap.count(businessLine[i]) && isValid(code[i])){
                temp.push_back({umap[businessLine[i]] , code[i]});
            }
        }

        sort(temp.begin() , temp.end());
        vector<string>res ; 

        for(auto it : temp){
            res.push_back(it.second);
        }

        return res ; 
    }
};