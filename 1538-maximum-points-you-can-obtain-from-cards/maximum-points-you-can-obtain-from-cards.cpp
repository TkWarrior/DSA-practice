class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //constant window 
        int l = k-1 ; int r = cardPoints.size()-1;
        int sum = 0;
        int max_sum = 0;
        for(int i = 0 ; i<=l ; i++){
            sum = sum + cardPoints[i];
        }

        max_sum = max(max_sum , sum);

        while(l>=0){
            sum -=cardPoints[l];
            sum +=cardPoints[r];
            l--;
            r--;
            max_sum = max(max_sum,sum);
        }

        return max_sum;
    }
};