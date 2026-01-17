class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long divide = num/3;
        vector<long long>ans; 
        if((divide-1) + divide + (divide+1) == num){
            ans.push_back(divide-1);
            ans.push_back(divide);
            ans.push_back(divide+1);
        }

        return ans ;
    }
};