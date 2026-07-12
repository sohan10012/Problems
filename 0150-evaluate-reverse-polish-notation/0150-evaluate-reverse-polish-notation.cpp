class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
        for(string s : tokens){
            if(s == "+" || s == "/" || s == "-" || s == "*" ){
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();

                if(s == "+") {
                    st.push(n1+n2);  
                }
                else if(s == "-"){
                    st.push(n1 - n2);  
                }
                else if(s == "*"){
                    st.push(n1 * n2);
                }
                else{
                    st.push(n1 / n2);
                }
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};