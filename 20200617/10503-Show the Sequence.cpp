#include <bits/stdc++.h>
using namespace std;

int my_stoi(string str){
    stringstream ss(str);
    int n;
    ss >> n;

    return n;
}

int main(){
    string S;
    while(getline(cin, S)){
        if(S == "") break;

        // get Numbers and Operators
        stack<int> Numbers;
        stack<char> Op;
        int idx = 0;
        string tmp_str = "";
        while(S[idx] != ']'){
            if( S[idx] == '+' || S[idx] == '*' ){
                Op.push(S[idx]);

                Numbers.push(my_stoi(tmp_str));
                tmp_str = "";
            }
            else if( isdigit(S[idx]) || S[idx] == '-' ){
                tmp_str += S[idx];
            }
            idx++;
        }
        Numbers.push(my_stoi(tmp_str));
        
        // get terms
        int terms;
        tmp_str = "";
        for(int i=idx+1; i<S.length(); i++){
            if( isdigit(S[i]) ){
                tmp_str += S[i];
            }
        }
        terms = my_stoi(tmp_str);


        // making the Sequence
        vector<long long int> PreSequence;
        vector<long long int> Sequence;
        int b = Numbers.top();
        Numbers.pop();
        int a = Numbers.top();
        Numbers.pop();
        char op = Op.top();
        Op.pop();

        // 處理最裡面的那一組[a+[b]]
        Sequence.push_back(a);
        while(Sequence.size() != terms){
            Sequence.push_back(Sequence.back()+b);   
        }
        
        while(Numbers.size() > 0){
            a = Numbers.top();
            Numbers.pop();
            op = Op.top();
            Op.pop();

            PreSequence = Sequence;
            Sequence.clear();
            
            if(op == '+'){
                idx = 0;
                Sequence.push_back(a);
            }
            else if(op == '*'){
                idx = 1;
                Sequence.push_back(a * PreSequence[0]);
            } 

            while(Sequence.size() != terms){
                if(op == '+')
                    Sequence.push_back( Sequence.back() + PreSequence.at(idx) );
                else if(op == '*')
                    Sequence.push_back( Sequence.back() * PreSequence.at(idx) );
                
                idx++;
            }
        }
        

        // print output
        for(int i=0; i<terms; i++){
            printf("%lld", Sequence[i]);
            if(i != terms-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}