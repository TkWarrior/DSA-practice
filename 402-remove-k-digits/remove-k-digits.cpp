class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int>arr;
        int n = arr.size();
        int len = num.size();
        string ans = "";
        stack<char>st;
        int count = 0;
        
        for(char ch:num){
            while(!st.empty() && st.top()>ch && k>0){
                st.pop();
                k--;
            }

            st.push(ch);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        size_t pos = ans.find_first_not_of('0');
        ans = (pos == std::string::npos) ? "0" : ans.substr(pos);
        return ans;
       
    }
};