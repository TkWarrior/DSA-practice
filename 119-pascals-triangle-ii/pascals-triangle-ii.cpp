class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int i = 0 ; i<rowIndex ; i++){
            ans = ans * (rowIndex-i);
            ans = ans/(i+1);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};