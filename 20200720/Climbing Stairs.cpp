#include <bits/stdc++.h>
using namespace std;

// 1 2 3 5 8

string my_toString(long long int n){
    stringstream ss;
    ss << n;
    return ss.str();
}

string Big_Add(string A, string B){
    int num1[25] = {0};
    int num2[25] = {0};
    int sum[25] = {0};

    for(int i=0; i<A.length(); i++){
        num1[i] = A[A.length()-1-i] - '0';        
    }
    for(int i=0; i<B.length(); i++){
        num2[i] = B[B.length()-1-i] - '0';        
    }

    // adding
    int carry = 0;
    for(int i=0; i<25; i++){
        sum[i] = num1[i] + num2[i] + carry;
        if(sum[i] >= 10){
            carry = sum[i] / 10;
            sum[i] %= 10;
        }
        else{
            carry = 0;
        }
    }

    // get the result
    int start;
    stringstream ss;
    for(int i=24; i>=0; i--){
        if(sum[i] != 0){
            start = i;
            break;
        }
    }
    for(int i=start; i>=0; i--){
        ss << sum[i];
    }
    
    return ss.str();
}

int main(){
    long long int ways[91] = {0};
    ways[1] = 1;
    ways[2] = 2;
    for(int i=3; i<=90; i++){
        ways[i] = ways[i-1] + ways[i-2];
    }

    // 會超出long long的另外用大數處理
    string waysBig[11]; // for n from 91 to 100
    waysBig[1] = Big_Add(my_toString(ways[90]), my_toString(ways[89]));  // 91
    waysBig[2] = Big_Add(waysBig[1], my_toString(ways[90])); // 92
    for(int i=3; i<=10; i++){
        waysBig[i] = Big_Add(waysBig[i-1], waysBig[i-2]);
    }


    int n;
    cin >> n;
    if(n<=90)
        cout<<ways[n]<<endl;
    else
        cout<<waysBig[n-90]<<endl;

    return 0;
}

// long long int table[101] = {0};
// long long int climbStairs(int n){
//     if(table[n] != 0) return table[n];

//     long long int result;
//     if(n == 1 || n == 2) 
//         result = n;
//     else{
//         result = climbStairs(n-1) + climbStairs(n-2);
//     }
//     table[n] = result;

//     return result;
// }

// int main(){
//     for(int i=1; i<=100; i++){
//         cout<<i<<":\t"<<climbStairs(i)<<endl;
//     }
// }