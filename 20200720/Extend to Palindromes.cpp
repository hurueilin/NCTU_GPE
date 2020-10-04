#include <bits/stdc++.h>
using namespace std;

void computeFailureFunction(string pattern, int failure[]){
    int q = failure[0] = -1;
    
    for(int i=1; i<pattern.length(); i++){
        while( (q >= 0) && (pattern[q+1] != pattern[i]) ){
            q = failure[q];
        }
        if(pattern[q+1] == pattern[i]){
            q++;
        }
        failure[i] = q;
    }
}

int KMP_cutPoint(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    
    int failure[m];
    computeFailureFunction(pattern, failure);
    
    int q = -1;
    for(int i=0; i<n; i++){
        while((q >= 0) && (pattern[q+1] != text[i]) ){
            q = failure[q];
        }
        if(pattern[q+1] == text[i]){
            q++;
        }
        // if(q == m-1){
        //     printf("valid shift: %d\n", i-(m-1));
        //     q = failure[q];
        // }    
    }
    return q; // 最後的matched position
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str == "") break;

        string str2 = "";
        for(int i=str.length()-1; i>=0; i--){
            str2 += str[i];
        }

        int cutPoint = KMP_cutPoint(str, str2);
        cout<<str;
        for(int i=cutPoint+1; i<str2.length(); i++){
            cout<<str2[i];
        }
        cout<<endl;
    }
    return 0;
}