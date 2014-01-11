class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(!tokens.size()) return 0;
        if(tokens.size() == 1)
            return stoi(tokens.front());
            
        string op;
        int num1, num2;
        op = tokens.back();
        tokens.pop_back();
        
        int idx = tokens.size(), expectNum = 1;
        vector<string>::iterator it = tokens.end();
        vector<string> aux;
        while(true){
            it--;
            idx--;
            if(isOperator(tokens[idx])){
                expectNum += 1;
            }else if(--expectNum == 0){
                aux.insert(aux.begin(), it, tokens.end());
                tokens.erase(it, tokens.end());
                num1 = evalRPN(tokens);
                num2 = evalRPN(aux);
                break;
            }
        }

        if(op == "+"){
            return num1 + num2;
        }else if(op == "-"){
            return num1 - num2;
        }else if(op == "*"){
            return num1 * num2;
        }else if(op == "/"){
            return num1 / num2;
        }else{
            cout << "wrong operator\n";
        }
    }
    
    int str2i(string s){
        if(s[0] == '-'){
            s.erase(s.begin());
            return -stoi(s);
        }
        return stoi(s);
    }
    
    bool isOperator(string s){
        return s == "+" || s == "-"
            || s == "*" || s == "/";
    }
};