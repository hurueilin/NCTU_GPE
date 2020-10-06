#include <bits/stdc++.h>
using namespace std;

int Catalan(int n){
    if(n == 0 || n == 1)
        return 1;
    else{
        int sum=0;
        for(int i=0; i<n; i++){
            sum = sum + Catalan(i) * Catalan(n-1-i);
        }
        return sum;
    }
}

int main(){
    int n;
    int flagFirst = 1;
    while(scanf("%d", &n) == 1){
        if(!flagFirst) cout <<endl;
        flagFirst = 0;
        cout << Catalan(n) << endl;
    }

    return 0;
}