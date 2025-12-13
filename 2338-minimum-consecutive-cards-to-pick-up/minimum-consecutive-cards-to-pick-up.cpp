class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int l = 0 ;
        int r = 0 ;
        int n = cards.size();
        int mini = INT_MAX ;
        unordered_map<int,int>umap ;

        while(r<n){
            if(umap.find(cards[r])!=umap.end()){
                if(umap[cards[r]]>=l){
                    l = umap[cards[r]];    
                    mini = min(mini , r-l+1);      
                }                
            }
            umap[cards[r]]=r ;     
            r++;
        }
        for(auto&it :umap){
            cout<<it.second;
        }
        if(mini==INT_MAX){
            return -1 ;
        }
        cout<<l ; 
        cout<<mini;
        return mini ;
    }
};