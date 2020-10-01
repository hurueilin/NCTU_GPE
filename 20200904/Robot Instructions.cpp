#include <bits/stdc++.h>
using namespace std;

int StringtoInt(string str){
    stringstream ss;
    string numStr = "";

    for(int i=0; i<str.length(); i++){
        if(str[i] >='0' && str[i] <='9')
            numStr += str[i];
    }

    int n;
    ss << numStr;
    ss >> n;
    return n;
}

void execution(string cmd, vector<string> cmdHistory, int &pos){
    if(cmd == "LEFT"){
        pos--;
    }
    else if(cmd == "RIGHT"){
        pos++;
    }
    else{
        execution(cmdHistory[StringtoInt(cmd) - 1], cmdHistory, pos);
    }
}

int main(){
    int Cases;
    cin >> Cases;

    while(Cases--){
        int instructions;
        cin >> instructions;
        cin.ignore(100, '\n');

        // init
        vector<string> cmdHistory;
        int pos = 0;
        while(instructions--){
            string cmd;
            getline(cin, cmd);
            cmdHistory.push_back(cmd);

            execution(cmd, cmdHistory, pos);
        }
        cout<<pos<<endl;
    }

    return 0;
}