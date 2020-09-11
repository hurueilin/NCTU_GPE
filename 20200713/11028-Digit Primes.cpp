#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;

    // <sol 1> check factors from 2 to sqrt(n)
    // for(int i=2; i*i <= n; i++){
    //     if(n % i == 0)
    //         return false;
    // }

    // <sol 2> omit Multiples of 2
    if(n % 2 == 0) 
        return n == 2;
    for(int i=3; i*i <= n ; i += 2){
        if(n % i == 0)
            return false;
    }

    return true;
}

int digitSum(int n){
    int sum = 0;
    while(n != 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    int Cases;
    scanf("%d", &Cases);
    
    int a, b;
    while(Cases--){
        scanf("%d %d", &a, &b);

        int result = 0;
        for(int num=a; num<=b; num++){
            if(isPrime(num)){
                if(isPrime(digitSum(num))){
                    result++;
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}