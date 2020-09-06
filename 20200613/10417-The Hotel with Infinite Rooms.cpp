#include <bits/stdc++.h>
using namespace std;

int main(){
    int S;
    long long int D;

    while(cin>>S>>D){
        long long int sum = S;
        int k = S;
        while(sum < D){
            k++;
            sum += k; 
        }
        cout<<k<<endl;
    }
    return 0;
}