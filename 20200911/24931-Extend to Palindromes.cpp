#include <bits/stdc++.h>
using namespace std;

// KMP algorithm: search Pattern in Text
// T: Text
// P: Pattern

void ComputeFailureFunction(string pattern, int failure[]){
    int q = failure[0] = -1; // q indicates the position of matched char in pattern

    for(int i=1; i<pattern.length(); i++){
        while( (q >= 0) && (pattern[q+1] != pattern[i]) ) // next char does not match
            q = failure[q];
        
        if(pattern[q+1] == pattern[i]) // next char matches
            q = q + 1;
        
        failure[i] = q;
    }
}

int KMP(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    int failure[m];

    ComputeFailureFunction(pattern, failure);

    // i indicates the current position of text (no looking back!)
    // q indicates the position of matched char in pattern
    int i=0, q=-1;
    for(; i<n; i++){
        while( (q >= 0) && (pattern[q+1] != text[i]) ) // next char does not match
            q = failure[q];

        if(pattern[q+1] == text[i]) // next char matches
            q = q + 1;
        
        // if(q == m-1){
        //     cout<<"Pattern occurs with shift: "<< i - (m-1) << endl;
        //     q = failure[q]; // look for the next match
        // }
    }
    return q; // 最後的 matched position in pattern
}

int main(){
    string Str;

    while(getline(cin, Str)){
        if(Str == "") break;

        string StrReverse = "";
        for(int i=Str.size()-1; i>=0; i--){
            StrReverse += Str[i];
        }

        int cut_pos = KMP(Str, StrReverse);
        cout<<Str;
        for(int i = cut_pos + 1; i<StrReverse.size(); i++)  cout<<StrReverse[i];
        cout<<endl;
    }

    return 0;
}