class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0 ;
        int j = 0 ;
        unordered_map<int,int>mp;
        int n = fruits.size();
        int mx_tree = 0 ;

        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            mx_tree = max(mx_tree , j-i+1);
            j++;
        }

        return mx_tree;
    }
};