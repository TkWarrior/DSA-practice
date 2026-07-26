class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int n = fruits.size();
        int i = 0 ;
        int j = 0 ;
        int maxi = 0 ;

        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }  
            maxi = max(maxi , j-i+1);
            j++;
        }
        
        return maxi ;
    }
};