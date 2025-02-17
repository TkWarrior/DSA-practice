class Solution {
public:
    vector<int> generateRow(int row){
        long long temp = 1;
        vector<int>rowAns;
        rowAns.push_back(1);
        for(int i = 1 ; i<row ; i++){
            temp = temp * (row-i);
            temp = temp/i;
            rowAns.push_back(temp);
        }
        return rowAns;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1 ; i<=numRows ;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};