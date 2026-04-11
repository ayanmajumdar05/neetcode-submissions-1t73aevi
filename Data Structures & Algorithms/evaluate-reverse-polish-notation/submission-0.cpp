class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        if(tokens.size() == 0){return 0;}
        for(string s: tokens)
        {
            if(s == "+" || s == "-" || s == "*" || s == "/" ) // operator check
            {
                int r = st.back(); st.pop_back();
                int l = st.back(); st.pop_back();

                if(s == "+") st.push_back(l + r);
                else if(s == "-") st.push_back(l - r);
                else if(s == "*") st.push_back(l * r);
                else if(s == "/") st.push_back(l / r);
            }
            else
            {
                st.push_back(std::stoi(s));
            }
        }
        return st.back();
    }
};
