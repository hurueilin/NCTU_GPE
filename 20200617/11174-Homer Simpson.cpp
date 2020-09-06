#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, t;
    while(cin>>m>>n>>t){
        if(m>n) swap(m,n);

        // m*x + n*y = t
        // 先全部換成burger m
        int maxBurgerCount = t / m;
        int remainTime = t % m;

        for(int x = maxBurgerCount-1; x>=0 && remainTime!=0; x--){ // remainTime==0表示完全不用喝啤酒，離開for loop
            int currentRemainTime = t - x*m;
            int y = currentRemainTime / n;
            currentRemainTime = currentRemainTime % n;

            // 若beer數可以更少(餘數更小)，用buger m兌換buger n
            if(currentRemainTime < remainTime){
                maxBurgerCount = x + y;
                remainTime = currentRemainTime;
            }
        }


        if(remainTime) cout<<maxBurgerCount<<" "<<remainTime<<endl;
        else cout<<maxBurgerCount<<endl;
    }
    return 0;
}