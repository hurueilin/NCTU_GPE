#include <bits/stdc++.h>
using namespace std;

int my_stoi(string str){
    stringstream ss;
    int n;
    ss << str;
    ss >> n;
    return n;
}

int calculate(int a, int b, char op){
    if(op == '+') return a+b;
    else if(op == '-') return a-b;
    else if(op == '*') return a*b;
    else if(op == '/') return a/b;
    else if(op == '%') return a%b;
}

int prefixEvaluation(vector<int> Numbers, vector<char> Operators, vector<int> ordering){
    stack<int> NumberStack;

    int numPtr = 0, opPtr = 0;
    for(int i=0; i<ordering.size(); i++){
        if(ordering[i] == 0){
            if(numPtr > Numbers.size()) return INT_MAX;
            
            NumberStack.push(Numbers[numPtr]);
            numPtr++;
        }
        else if(ordering[i] == 1){
            if(NumberStack.size() < 2 || opPtr > Operators.size()) return INT_MAX;

            int a = NumberStack.top();
            NumberStack.pop();
            int b = NumberStack.top();
            NumberStack.pop();
            char op = Operators[opPtr];

            int result = calculate(a, b, op);
            NumberStack.push(result);

            opPtr++;
        }
    }

    if(NumberStack.size() > 1) return INT_MAX;
    return NumberStack.top();
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str == ".") break;
        
        vector<int> Numbers;
        vector<char> Operators;
        vector<int> ordering; // 0:number, 1:operator
        string tmpNum = "";
        for(int i=0; i<str.size(); i++){
            if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'){
                Operators.push_back(str[i]);
                ordering.push_back(1);
            }
            else if(str[i] == ' '){
                if(tmpNum != ""){
                    Numbers.push_back(my_stoi(tmpNum));
                    ordering.push_back(0);
                }
                tmpNum = "";
            }
            else{
                tmpNum += str[i];
            }
        }
        if(tmpNum != ""){ // for the last number
            Numbers.push_back(my_stoi(tmpNum));
            ordering.push_back(0);
        }
        

        reverse(Numbers.begin(), Numbers.end());
        reverse(Operators.begin(), Operators.end());
        reverse(ordering.begin(), ordering.end());


        int ans = prefixEvaluation(Numbers, Operators, ordering);
        
        if(ans == INT_MAX) cout<<"illegal\n";
        else cout<<ans<<endl;
    }
    return 0;
}