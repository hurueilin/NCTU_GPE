#include <bits/stdc++.h>
using namespace std;

int PrimeTable[3501];

bool isPrime(int n){
    if(n < 2) return false;
    if(n % 2 == 0)
        return n == 2;
    for(int i=3; i*i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

void buildPrimeTable(){
    int index = 0;
    int n = 2;
    while(index < 3501){
        if(isPrime(n)){
            PrimeTable[index] = n;
            index++;
        }
        n++;
    }
}

// int nextPrime(int start){
//     int next = start+1;
//     while(!isPrime(next)){
//         next++;
//     }
//     return next;
// }

int main() {
    buildPrimeTable();

    int n, players;
    while(cin>>n){
        if(n == 0) break;

        players = n;
        bool isKilled[3502] = {false};
        int countOffKilling;
        int currentCountOff;
        int pos = 0;
        int PrimeTableIndex =  -1;
        
        while(players > 1){
            countOffKilling = PrimeTable[++PrimeTableIndex];
            currentCountOff = 1;
            // cout<<"====countOffKilling: "<<countOffKilling<<"====\n";
            
            while(currentCountOff <= countOffKilling){
                pos++;
                if(pos > n) pos = pos % n;
                // cout<<"the pos now is: "<<pos<<endl;
                if(isKilled[pos] ==  true) continue; // skip the dead one
                
                if(currentCountOff == countOffKilling){
                    // cout<<"player at pos: "<<pos<<" is now killed\n";
                    players--;
                    isKilled[pos] = true;
                    break;   
                }
                else{
                    // cout<<"currentCountOff: "<<currentCountOff<<endl;
                    currentCountOff++;
                }
            }
        }
        for(int i=1; i<=n; i++)
            if(isKilled[i] == false){
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}