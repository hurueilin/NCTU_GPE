#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    int Case=0;

    while(cin>>S){
        Case++;
        cout<<"Case "<<Case<<":\n";

        int numofquery;
        cin>>numofquery;
        while(numofquery--){
            int i, j;
            cin>>i>>j;

            bool sameFlag=true;
            for(int k=min(i,j); k<max(i,j); k++){
                if(S.at(k) == S.at(k+1)){
                    sameFlag = true;
                }
                else{
                    sameFlag = false;
                    break;
                }
            }
            if(sameFlag) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}