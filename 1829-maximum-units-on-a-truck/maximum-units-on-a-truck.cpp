class Solution {
public:
   
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a , vector<int>&b) {
            return a[1] > b[1] ; 
        });
        
        int total = 0 ;
        
        for(int i = 0 ; i<boxTypes.size() ; i++){
           int takeBox = min(boxTypes[i][0],truckSize);  
           total += takeBox*boxTypes[i][1];
           truckSize -= takeBox;
           if(truckSize==0) break;
        }

        return total;

        }
    
};