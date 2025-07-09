class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    
        int n = arr.size();
        map<int,int>mpp;
        vector<int>arrCopy(arr);
        int rank = 1;
        sort(arrCopy.begin(),arrCopy.end());

        for(int i = 0 ; i<arrCopy.size() ; i++){
            if(i>0 && arrCopy[i]>arrCopy[i-1]){
                rank++;
            }
            mpp[arrCopy[i]] = rank;
        }
        
        for(int i = 0 ; i<n ; i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};