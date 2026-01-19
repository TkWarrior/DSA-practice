class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st ;
        int res = 0 ;
        for(string str : tokens){

            if(str == "+" || str == "-" || str == "*" || str == "/"){

                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();

                if(str == "+"){
                    st.push(n1+n2);
                }
                else if(str == "-"){
                    st.push(n2-n1);
                }
                else if(str == "*"){
                    st.push(n1*n2);
                }
                else if(str == "/"){
                    st.push(n2/n1);
                }
            }else{
                st.push(stoi(str));
            }    
        }
        cout<<st.top()<<endl;
        return st.top();
    }
};