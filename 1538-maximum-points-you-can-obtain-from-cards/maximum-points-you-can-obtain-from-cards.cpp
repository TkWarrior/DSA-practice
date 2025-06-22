class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //constant window 
        int  max_sum  = 0 ;
        int left_sum = 0 , right_sum = 0;
        int sum = 0 ;
        int n = cardPoints.size();
        int right_index = n-1;
        for(int i = 0 ; i<k ; i++){
            left_sum += cardPoints[i];
            sum = left_sum+right_sum;
        }
        max_sum = max(max_sum,sum);

        for(int i = k-1 ; i>=0 ; i--){
            left_sum -= cardPoints[i];
            right_sum += cardPoints[right_index--];
            sum = left_sum + right_sum;
            max_sum = max(max_sum,sum);
        }

        return max_sum;
    }
};