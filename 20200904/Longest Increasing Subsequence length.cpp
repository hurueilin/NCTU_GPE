#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; 

    int Num[n];
    for(int i=0; i<n; i++){
        cin >> Num[i];
    }

    int LIS_length[65535] = {0}; // LIS_length[i]: the LIS length of Num[0...i]
    
    // 初始化。每一個數字本身就是長度為一的 LIS。
    for(int i=0; i<n ; i++){
        LIS_length[i] = 1; 
    }
    for(int i=0; i<n; i++){
        // 看 Num[i] 可以接在哪些數字後面
        for(int j=0; j<i; j++){
            if(Num[j] < Num[i])
                LIS_length[i] = max(LIS_length[i], LIS_length[j] + 1);
        }
    }

    // LIS_length[]中最大的值即為 LIS 的長度
    int len=0;
    for(int i=0; i<n; i++)
        len = max(len, LIS_length[i]);
    cout<<len<<endl;

    return 0;
}