class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        if(n==1) return 1 ;

        vector<pair<int,int>>combo ;

        for(int i = 0 ; i<n ; i++){
            combo.push_back({position[i] , speed[i]});
        }

        sort(combo.rbegin() , combo.rend());
        vector<double>stack ;

        for(auto&p : combo){ 
            double time = ((double)(target - p.first)/p.second);
            stack.push_back(time);
            if(stack.size()>=2 && stack.back()<=stack[stack.size()-2]){
                stack.pop_back();
            }
        }

        return stack.size();

    }
};