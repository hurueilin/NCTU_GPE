#include <bits/stdc++.h>
using namespace std;

// maximum: 先加再乘(+的優先權高於*)
// minimum: 先乘再加(*的優先權高於+)

int my_stoi(string num_str){
    stringstream geek(num_str);

    int x=0;
    geek >> x;

    return x;
}

void setNumbers(vector<int> &opPosition, vector<int> &numbers, string S){
    vector<int>::iterator iter;
    int i=0, num;
    string tmp_str;
    for(iter=opPosition.begin(); iter!=opPosition.end(); iter++){
        // cout<< *iter << " ";
        tmp_str = S.substr(i, *iter);
        num = my_stoi(tmp_str);
        numbers.push_back(num);
        i = *iter+1;
    }
    tmp_str = S.substr(i, S.length());
    num = my_stoi(tmp_str);
    numbers.push_back(num);
}

// 求maximum: +的優先權高於*
long long int calMaximum(vector<int> numbers, vector<char> operators){
    long long int maximum=1;
    vector<char>::iterator iterOp = operators.begin();
    vector<int>::iterator iterNum;
    while(iterOp != operators.end()){
        if(*iterOp != '+'){
            iterOp++;
            continue;
        }

        int index = distance(operators.begin(), iterOp);
        int tmp_str_add = numbers.at(index) + numbers.at(index+1);
        iterNum = numbers.begin() + index;
        numbers.erase(iterNum);
        numbers.erase(iterNum);
        numbers.insert(iterNum, tmp_str_add);

        operators.erase(iterOp);
        iterOp = operators.begin();
    }
    for(iterNum=numbers.begin(); iterNum!=numbers.end(); iterNum++){
        maximum *= *iterNum;
    }

    return maximum;
}

// 求minimum: *的優先權高於+
int calMinimum(vector<int> numbers, vector<char> operators){
    int minimum=0;
    vector<char>::iterator iterOp = operators.begin();
    vector<int>::iterator iterNum;
    while(iterOp != operators.end()){
        if(*iterOp != '*'){
            iterOp++;
            continue;
        }

        int index = distance(operators.begin(), iterOp);
        int tmp_str_multiply = numbers.at(index) * numbers.at(index+1);
        iterNum = numbers.begin() + index;
        numbers.erase(iterNum);
        numbers.erase(iterNum);
        numbers.insert(iterNum, tmp_str_multiply);

        operators.erase(iterOp);
        iterOp = operators.begin();
    }
    for(iterNum=numbers.begin(); iterNum!=numbers.end(); iterNum++){
        minimum += *iterNum;
    }

    return minimum;
}

int main(){
    int Case;
    cin>>Case;
    while(Case--){
        string S;
        cin>>S;
        
        vector<char> operators;
        vector<int> opPosition;
        vector<int> numbers;
        for(unsigned int i=0; i<S.length(); i++){
            if(S[i]=='+' || S[i]=='*'){
                operators.push_back(S[i]);
                opPosition.push_back(i);
            }
        }
        setNumbers(opPosition, numbers, S);

        printf("The maximum and minimum are %lld and %d.\n", calMaximum(numbers,operators), calMinimum(numbers, operators));
    }
    return 0;
}