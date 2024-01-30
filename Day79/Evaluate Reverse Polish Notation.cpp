class Solution {
public:
    int evalRPN(vector<string>& tokens){
        stack<long> st;
        long a1,a2,a3 = 0;
        for(int i = 0; i < tokens.size(); i++){
            
            if( isSymbol(tokens[i])){
                a1 = st.top();
                st.pop();
                a2 = st.top();
                st.pop();
                a3 = solve(tokens[i][0],a2,a1);
                st.push(a3);
            }
            else{
                a3 = stoi(tokens[i]);
                st.push(a3);
            }
        }
        return a3;
    }
        long solve(char symbol,long a1,long a2){
            long a3 = 0;
            switch(symbol){
                case '+': a3 = a1+a2;
                    break;
                case '-': a3 = a1-a2;
                    break;
                case '*': a3 = a1*a2;
                    break;
                case '/': if(a2 != 0) a3 = a1/a2; else a3 = LONG_MAX; break;
                    break;
                        
            }
            return a3;
        }
        bool isSymbol(string ch){
            if((ch.length() <= 1) && (ch[0] == '+' || ch[0] == '-' || ch[0] == '/' || ch[0] == '*'))
                return true;
            else
                return false;
        }
    
};
