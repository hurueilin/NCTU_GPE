#include <bits/stdc++.h>
using namespace std;
#define SQRT_INT_MAX 46341


// build Prime Table from 0 ~ sqrt(INT_MAX)=46341
// using SieveOfEratosthenes
bool isPrime[SQRT_INT_MAX+1];
vector<int> primes;
void buildPrimeTable(){
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;
    for(int p=2; p*p <= SQRT_INT_MAX; p++){
        if(isPrime[p] == true){
            for(int n=p*p; n <= SQRT_INT_MAX; n += p){
                isPrime[n] = false;
            }
        }
    }
    for(int n=2; n<SQRT_INT_MAX; n++){
        if(isPrime[n]){
            primes.push_back(n);
        }
    }
}

bool checkisPrime(int n){
    if(n <= SQRT_INT_MAX){
        return isPrime[n];
    }
    else{
        for(unsigned int i=0; i<primes.size() && primes[i]<n; i++){
            if(n % primes[i] == 0) return false;
        }
        return true;
    }
}

int main(){
    buildPrimeTable();
    
    int L, U;
    while(cin>>L>>U){
        vector<int> primesBetweenLU;
        
        for(long long int n=L; n<=U; n++){
            // if(n <= SQRT_INT_MAX){
            //     if(isPrime[n]){
            //         primesBetweenLU.push_back(n);
            //     }
            // }
            // else{
            //     bool isPrime=false;
            //     for(unsigned int i=0; i<primes.size(); i++){
            //         if(primes.at(i) > n) break;
                    
            //         if(n % primes.at(i) == 0){
            //             isPrime = false;
            //             break;
            //         }
            //         else{
            //             isPrime = true;
            //         }
            //     }
            //     if(isPrime) primesBetweenLU.push_back(n);
            // }
            if(checkisPrime(n)) primesBetweenLU.push_back(n);
        }

        // for(int x:primesBetweenLU){
        //     cout<<x<<endl;
        // }

        if(primesBetweenLU.size() < 2){
            cout<<"There are no adjacent primes.\n";
        }
        else{
            int minDist=INT_MAX, maxDist=0, dist;
            int p1, p2, p3, p4;
            for(unsigned int i=0; i<primesBetweenLU.size()-1; i++){
                dist = primesBetweenLU.at(i+1) - primesBetweenLU.at(i);
                if(dist < minDist){
                    minDist = dist;
                    p1 = primesBetweenLU.at(i);
                    p2 = primesBetweenLU.at(i+1);
                }
                if(dist > maxDist){
                    maxDist = dist;
                    p3 = primesBetweenLU.at(i);
                    p4 = primesBetweenLU.at(i+1);
                }
            }
            cout<<p1<<","<<p2<<" are closest, "<<p3<<","<<p4<<" are most distant.\n";
        }
    }
    return 0;
}